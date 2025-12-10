/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 03:11:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/10 03:17:37 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	std::string string("HI THIS IS BRAIN");
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "String address: " << &string << std::endl;
	std::cout << "StringPTR address: " << stringPTR << std::endl;
	std::cout << "StringREF address: " << &stringREF << std::endl;
	std::cout << "String value: '" << string << "'" << std::endl;
	std::cout << "StringPTR value: '" << *stringPTR << "'" << std::endl;
	std::cout << "StringREF value: '" << stringREF << "'" << std::endl;
}