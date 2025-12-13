/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:59:39 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/14 00:24:42 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string &in){
	this->_in = in;
	this->_out = in + ".replace";
}
Sed::~Sed(){
}
void	Sed::replace(const std::string &search, const std::string &replace){
	std::stringstream	buffer;
	std::ifstream		ifs(this->_in.c_str());
	std::string			content;
	size_t				pos = 0;

	if (search.empty()){
		std::cerr << "Error: put something in the search part" << std::endl;
		return;
	}
	if (!ifs.is_open()){
		std::cerr << "Error: Unable to open \"" << this->_in <<"\""<< std::endl;
		return;
	}
	buffer << ifs.rdbuf();
	content = buffer.str();

	ifs.close();
	while ((pos = content.find(search, pos)) != std::string::npos){
		content.erase(pos, search.length());
		content.insert(pos, replace);
		pos += replace.length();
	}
	std::ofstream		ofs(this->_out.c_str());
	if (!ofs.is_open()){
		std::cerr << "Error: Unable to create \"" << this->_out <<"\""<< std::endl;
		return;
	}
	ofs << content;
	ofs.close();
}