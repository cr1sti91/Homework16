#include "Functii_teme.h"


int main()
{
	std::cout << "Tema pe acasa:" << std::endl;
	const std::string optiuni_intrare{ R"(
			1.Tema agenda telefonica
			2.Tema biblioteca personala
	)" };

	//Afisam optiunile posibile
	std::cout << "Optiuni:" << std::endl << optiuni_intrare << std::endl;

	//Citim optiunea necesara de la tastatura
	std::cout << "Introduce numarul din dreptul optiunii necesare: ";
	short optiune{};
	std::cin >> optiune;
	std::cout << std::endl;

	//Executam functia ce corespunde optiunei introduse
	switch (optiune)
	{
	case 1: temaAgendaTelefonica();
		break;
	case 2: temaBibliotecaPersonala();
		break;
	default: std::cout << "Optiune incorecta!" << std::endl;
	}

}
