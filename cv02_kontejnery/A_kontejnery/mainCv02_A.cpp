
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using std::cout;
using std::endl;
void Test()
{
	std::string aa;
	std::string bb = " R1 ";
	std::string cc = std::to_string(3.1415926);
	std::string dd = "  Cislo = " + std::to_string(123.456);
	dd[1] = '>'; //pro bezpecnost - at
	//prilozeni uvozovek - bezpecnostni napriklad pro program files
	aa = " AA ";
	
	std::cout << aa  << bb << cc << std::endl;
	std::cout << std::quoted(dd, '*') << std::endl;

	const char* txt1 = dd.c_str();
	//dokud pouzivam iterator, neni mozne manipulovat s puvodnim objektem
	char* txt2 = dd.data();
	std::cout << txt1 << "  " << (void*) txt1 << "  " << reinterpret_cast<void*>(txt2) << std::endl; //void -pretypovani na pointer null

	std::string::size_type n; //specialni typ primo string
	
	n = dd.rfind("s");
	std::string s4;
	if ((n < dd.size() - 1) && n != std::string::npos && n > 0) //pokud jsme v rozsahu, npos - nenasli jsme cislo v retezci
		s4 = dd.substr(n - 1, 3);

	std::cout << s4 << std::endl;
	std::string_view sv(dd.data() + 2, 4); //span v ALD - rikal, kam doposud vidim. Data - pointer na zacatek pole
	std::cout << sv << std::endl;
}

struct CFilePath
{
	std::string iDrive;
	std::string iPath;
	std::string iName;
	std::string iOrigin; //originalni cesta
	std::string iExt; //pripona

};
struct CFilePosition 
{
	std::string::size_type Path;
	std::string::size_type Slash;
	std::string::size_type Dot;
};
void main_A(size_t argc, const char* argv[])
{

	std::vector <CFilePath> actualCFilePath(argc);
	CFilePosition actualCFilePositions;

	for (size_t i = 0; i < argc; i++)
	{
		actualCFilePath[i].iOrigin = argv[i];
		cout << i + 1 << ". path:" << endl;
		cout << "Original: " << actualCFilePath[i].iOrigin << endl;
		actualCFilePositions.Path = actualCFilePath[i].iOrigin.rfind(":");
		//drive
		if (actualCFilePositions.Path != std::string::npos)
		{
			actualCFilePath[i].iDrive = actualCFilePath[i].iOrigin.substr(0, actualCFilePositions.Path + 1); //dostanu C:, D:, E: ...
			//actualCFilePath[i].iOrigin = actualCFilePath[i].iOrigin.substr(0, actualCFilePositions.Path + 1);
		}
		else
		{
			actualCFilePath[i].iDrive = "";
			actualCFilePath[i].iPath = actualCFilePath[i].iOrigin;
		}
		//path - ukoncovaci znak ma dvojity backslash \\
		
		actualCFilePositions.Slash = actualCFilePath[i].iOrigin.rfind("\\");
		if (actualCFilePositions.Slash != std::string::npos)
		{
			actualCFilePath[i].iPath = actualCFilePath[i].iOrigin.substr(actualCFilePositions.Path+2, 
																		actualCFilePositions.Slash - (actualCFilePositions.Path + 2));
			/*actualCFilePath[i].iPath = actualCFilePath[i].iOrigin.substr(0, actualCFilePositions.Slash);*/ 
		}
		else
		{
			actualCFilePath[i].iPath = "";
		}
		//name - ukoncovaci znak ma .

		actualCFilePositions.Dot = actualCFilePath[i].iOrigin.rfind(".");
		if (actualCFilePositions.Dot != std::string::npos)
		{
			actualCFilePath[i].iName = actualCFilePath[i].iOrigin.substr(actualCFilePositions.Slash + 1, 
																		actualCFilePositions.Dot - (actualCFilePositions.Slash + 1) );
			actualCFilePath[i].iExt = actualCFilePath[i].iOrigin.substr(actualCFilePositions.Dot + 1);
		}
		else
		{
			actualCFilePath[i].iName = actualCFilePath[i].iOrigin.substr(actualCFilePositions.Slash + 1, 
																		actualCFilePositions.Dot - (actualCFilePositions.Slash + 1) );
		}
		cout << "Drive[" << actualCFilePath[i].iDrive << "]" << endl;
		cout << "Path[" << actualCFilePath[i].iPath << "]" << endl;
		cout << "Name[" << actualCFilePath[i].iName << "]" << endl;
		cout << "Extension[" << actualCFilePath[i].iExt << "]" << endl;

		cout << "\n" << endl;
		//for (size_t i = 0; i < 2; i++) 
		//{
		//	if (actualCFilePath[i].iOrigin == ":")
		//		ActualCFilePathPositions.posPath = i - 1;

		//}
		//posPath = actualCFilePath[i].iOrigin.rfind(":");
		

	}
	
}

//#include <filesystem>
//using namespace std::filesystem;

//void Ukazka()
//{
//	path curpath = current_path(); // zjištění aktuálního adresáře
//	std::cout << "Current path  : " << curpath << '\n'; // zobrazí celý název (v uvozovkách)
//
//	path actpath("."); // zjištění aktuálního adresáře
//	std::cout << "Actual  path  : " << actpath << '\n'; // zobrazí zadaný název
//	std::cout << "Actual absolut: " << absolute(actpath) << '\n'; // převede název na absolutní polohu 
//	actpath = absolute(actpath); // převedení z relativní na absolutní cestu a uložení
//	std::cout << "The path " << actpath << " decomposes into:\n"
//		<< "root-path " << actpath.root_path() << '\n'
//		<< "relative path " << actpath.relative_path() << '\n' << '\n';
//	// iterátor rozdělí na sekce
//	for (auto it = actpath.begin(); it != actpath.end(); ++it)
//		std::cout << *it << " | ";
//	std::cout << std::endl;
//
//	// prohlížení položek v adresáři bez podadresářů a bez "." a ".."; existuje i recursive_directory_iterator
//	// hodnoty directory_entry: jsou v něm hodnota path a další - jako například typ (link, ...) velikost, čas ...
//	// různé zobrazení
//	for (auto const& dir_entry : std::filesystem::directory_iterator{ actpath })
//		std::wcout << dir_entry.path() << '\n';
//
//	for (auto const& dir_entry : std::filesystem::directory_iterator{ actpath })
//		std::wcout << std::wstring(dir_entry.path()) << '\n';
//
//	// i s podadresáři
//	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ actpath })
//		std::wcout << std::wstring(dir_entry.path()) << '\n';
//}

int main()
{ 
	const char* pomargv[] = {  // pro snadnější ladění vytvořeno vlastní pole vstupních řetězcù v odpovídajícím formátu
		"c:\\adresar\\podad1\\podad2\\test.exe", // spuštěný program - první parametr
		"c:\\adresar\\podad1\\podad2\\x.cpp",	
		"c:\\adresar\\podad1\\x.cpp",	
		"e:\\adresar\\podad1\\podad2\\x.cpp",
		"x.cpp",               // předpoklad, že leží v aktuálním adresáři, ze kterého je spuštěný program (první parametr)
		"c:\\adresar\\podad1\\podad2\\x",
		"c:\\adresar\\podad1\\podad2\\x.abc.cpp",
		"c:\\adresar\\podad1\\test.h",
		"c:\\adresar\\podad1\\podad2\\test.cpp",
		"c:\\adresar\\podad1\\podad2\\podad3\\test.xls",
		"e:\\adresar\\podad1\\podad2\\test.hxx",
		"test.a.c",
		"test.b",
		nullptr
		};
	/*Ukazka();*/
	main_A(sizeof(pomargv), pomargv);   // začněte s voláním jednoho parametru, potom po jednom přidávejte a proti prvnímu testujte shodnost následujících (v základu je maximum 13)
	return 0;
}