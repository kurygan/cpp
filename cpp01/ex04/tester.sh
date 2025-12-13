#!/bin/bash

# Couleurs pour l'affichage
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Nom de l'exécutable
NAME="sed_is_for_losers"

# Nettoyage précédent
rm -f $NAME *.replace test_*.txt
clear

echo "--- COMPILATION ---"
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o $NAME

if [ ! -f ./$NAME ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi
echo -e "${GREEN}Compilation OK.${NC}\n"

# Fonction de test
run_test() {
    TEST_NAME=$1
    CONTENT=$2
    S1=$3
    S2=$4
    EXPECTED=$5
    FILENAME="test_${TEST_NAME}.txt"
    
    # Création du fichier source
    echo -n "$CONTENT" > $FILENAME
    
    # Exécution du programme
    ./$NAME $FILENAME "$S1" "$S2"
    
    # Vérification du fichier de sortie
    if [ -f "${FILENAME}.replace" ]; then
        RESULT=$(cat "${FILENAME}.replace")
        
        if [ "$RESULT" == "$EXPECTED" ]; then
            echo -e "[${GREEN}OK${NC}] $TEST_NAME"
        else
            echo -e "[${RED}KO${NC}] $TEST_NAME"
            echo "   Input:    '$CONTENT'"
            echo "   Replace:  '$S1' -> '$S2'"
            echo "   Expected: '$EXPECTED'"
            echo "   Got:      '$RESULT'"
        fi
    else
        # Cas spécial pour les tests qui doivent échouer (fichiers manquants, empty search...)
        if [ "$EXPECTED" == "ERROR" ]; then
             echo -e "[${GREEN}OK${NC}] $TEST_NAME (Correctly failed/skipped)"
        else
             echo -e "[${RED}KO${NC}] $TEST_NAME (Output file not created)"
        fi
    fi
}

echo "--- TESTS FONCTIONNELS ---"

# Test 1 : Remplacement simple
run_test "1_Basic" "Hello World" "World" "42" "Hello 42"

# Test 2 : Remplacement multiple
run_test "2_Multiple" "a b a c a" "a" "X" "X b X c X"

# Test 3 : Piège de la boucle infinie (a -> aa)
# Si ton code boucle, le script bloquera ici (ctrl+c pour arrêter)
run_test "3_InfiniteLoopTrap" "a" "a" "aa" "aa"

# Test 4 : Remplacement par chaîne vide (suppression)
run_test "4_Delete" "I do not like bugs" "not " "" "I do like bugs"

# Test 5 : Chaîne introuvable (ne doit rien changer)
run_test "5_NotFound" "Hello World" "Earth" "Mars" "Hello World"

# Test 6 : Chaîne complexe
run_test "6_Complex" "123123123" "123" "ABC" "ABCABCABC"

echo -e "\n--- TESTS D'ERREURS ---"

# Test 7 : Fichier inexistant
./$NAME do_not_exist.txt "a" "b" 2> /dev/null
if [ ! -f "do_not_exist.txt.replace" ]; then
    echo -e "[${GREEN}OK${NC}] 7_FileMissing (Handled correctly)"
else
    echo -e "[${RED}KO${NC}] 7_FileMissing (Should fail)"
fi

# Test 8 : Chaîne de recherche vide
# On crée un fichier valide pour être sûr que l'erreur vient du S1 vide
echo "test" > test_empty_search.txt
./$NAME test_empty_search.txt "" "b" 2> /dev/null
if [ ! -f "test_empty_search.txt.replace" ]; then
    echo -e "[${GREEN}OK${NC}] 8_EmptySearch (Handled correctly)"
else
    echo -e "[${RED}KO${NC}] 8_EmptySearch (Should fail)"
fi

# Test 9 : Arguments manquants
OUT=$(./$NAME arg1 arg2 2>&1)
if [[ $OUT == *"Error"* ]]; then
     echo -e "[${GREEN}OK${NC}] 9_BadArgs (Handled correctly)"
else
     echo -e "[${RED}KO${NC}] 9_BadArgs (Should print Error)"
fi

echo -e "\n--- NETTOYAGE ---"
rm -f $NAME *.replace test_*.txt
echo "Done."