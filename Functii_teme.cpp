#include "Functii_teme.h"

void temaAgendaTelefonica()
{
	short optiune{}; 
	bool iesireDinAplicatie{ false };
	std::string optiuni_rulare{ R"(
		1   Introducere contacte noi in agenda
		2   Afisare contacte
		3   Stergerea unui contact
		4   Stergerea tuturor contactelor
		5   Iesire din aplicatie
    )" };

	std::cout << "\t****** Agenda Telefonica ******" << std::endl;

	//Setam o agenda de contacte
	AgendaTelefonica agenda;

	while (!iesireDinAplicatie)
	{
		std::cout << optiuni_rulare << std::endl;
		std::cout << "\tOptiunea introdusa: ";
		std::cin >> optiune;
		system("CLS");

		switch (optiune)
		{
			case 1:
			{
				std::string numePersoana{}, numarTelefon{}, email{};
				std::cout << "\tIntrodu numele persoanei, numarul de telefon si email: ";
				std::cin >> numePersoana >> numarTelefon >> email;
				agenda.adaugareContact(numePersoana, numarTelefon, email);
				std::cout << "\tContactul a fost adaugat cu succes!" << std::endl;
			}break;

			case 2:
			{
				system("CLS");
				agenda.afisareContacte();
			}break;

			case 3:
			{
				std::cout << "\tIntrud indexul contactului ce urmeaza sa fie sters: ";
				size_t index{};
				std::cin >> index;
				agenda.stergereContact(index);
			}break;

			case 4:
			{
				agenda.stergereaTuturorContactelor();
				std::cout << "\tToate contactele au fost sterse!" << std::endl;
			}break;

			case 5:
			{
				iesireDinAplicatie = true;
			}break;

			default: 
			{
				std::cout << "\tOptiune incorecta!" << std::endl;
			}
		}
	}

	std::cout << "O zi frumoasa in continuare!" << std::endl;
}


//Functii pentru teme biblioteca personala
void adaugareCarti(std::vector<Carte>& biblioteca, Carte carte)
{
	biblioteca.push_back(carte);
}

void afisareCarti(const std::vector<Carte>& biblioteca)
{
	if (biblioteca.size() > 0) {
		for (size_t i{}; i < biblioteca.size(); i++)
		{
			std::cout << std::left << " [" << i + 1 << "]: ";
			std::cout << "Titlul : " << std::setw(30) << biblioteca.at(i).Titlul << " "
				<< "Autorul: " << std::setw(15) << biblioteca.at(i).Autorul << " "
				<< "Anul publicarii : " << biblioteca.at(i).anulPublicarii << std::endl << std::endl;
		}
	}
	else {
		std::cout << "\tSe pare ca inca nu ati adaugat carti in biblioteca!" << std::endl;
	}
}

void temaBibliotecaPersonala()
{
	std::vector<Carte> Biblioteca;
	short optiune{};
	bool iesireDinAplicatie{ false };

	std::string optiuni_rulare{ R"(
		1   Introduce o carte in biblioteca
		2   Afisare carti
		3   Iesire din aplicatie
    )" };

	std::cout << "\t****** Biblioteca Personala ******" << std::endl;


	while (!iesireDinAplicatie)
	{
		std::cout << optiuni_rulare << std::endl;
		std::cout << "\tOptiunea introdusa: ";
		std::cin >> optiune;
		system("CLS");

		switch (optiune)
		{
		case 1:
		{
			std::string titlul{}, autorul{};
			int anulPublicarii{};

			std::cout << "\tIntrodu titlul cartii: ";
			std::cin.ignore();
			std::getline(std::cin, titlul);

			std::cout << "\tIntrodu numele autorului: ";
			std::getline(std::cin, autorul);

			std::cout << "\tIntrodu anul publicarii: "; 
			std::cin >> anulPublicarii;

			Carte temp{ titlul, autorul, anulPublicarii };

			adaugareCarti(Biblioteca, temp);

			std::cout << "\tCartea a fost adaugata cu succes!" << std::endl;
		}break;

		case 2:
		{
			system("CLS");
			afisareCarti(Biblioteca);
		}break;

		case 3:
		{
			iesireDinAplicatie = true;
		}break;

		default:
		{
			std::cout << "\tOptiune incorecta!" << std::endl;
		}
		}
	}

	std::cout << "O zi frumoasa in continuare!" << std::endl;
}

