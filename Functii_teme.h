#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

//Temele
void temaAgendaTelefonica();
void temaBibliotecaPersonala();


//Structuri pentru temaAgendaTelefonica
struct Contact
{
	//Variabile membru
	std::string numePersoana; 
	std::string numarTelefon; 	
	std::string email; 	
};

struct AgendaTelefonica
{
	//Variabile membru
	std::vector<Contact> agendaContacte; 


	//Metode
	void adaugareContact(const std::string& numePersoana, 
	     const std::string& numarTelefon, const std::string& email)
	{
		agendaContacte.push_back(Contact{ numePersoana, numarTelefon, email });
	}


	void afisareContacte()
	{
		if (agendaContacte.size() > 0) {
			for (size_t i{}; i < agendaContacte.size(); i++)
			{	
				std::cout << std::left << " [" << i + 1 << "]: ";
				std::cout << std::setw(10) << agendaContacte.at(i).numePersoana << " "
					      << std::setw(13) << agendaContacte.at(i).numarTelefon << " "
				          << agendaContacte.at(i).email << std::endl << std::endl;
			}
		}
		else {
			std::cout << "\tSe pare ca inca nu ati adaugat contacte in agenta!" << std::endl;
		}
	}


	void stergereContact(size_t i)
	{
		if (i > agendaContacte.size()) {
			std::cout << "\tNu aveti nici un contact cu indexul " << i << std::endl;
			return;
		}
		std::cout << "\tContactul " << agendaContacte.at(i).numePersoana << " este sters!" << std::endl;
		agendaContacte.erase(agendaContacte.begin() + i); //este necesar un iterator
	};

	void stergereaTuturorContactelor()
	{
		agendaContacte.clear();
	}
};


//Structura pentru temaBibliotecaPersonala
struct Carte
{
	std::string Titlul{}; 
	std::string Autorul{}; 
	int anulPublicarii{};
};

