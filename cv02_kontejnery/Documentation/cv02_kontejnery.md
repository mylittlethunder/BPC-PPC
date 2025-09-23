\mainpage Zadání

# Obsah cvičení
V tomto cvičení se seznámíme s dalšími knihovnami jazyka C++. 
Toto cvičení slouží k demonstraci a seznámení se s možnostmi využití objektů jazyka C++ předtím, než začneme tvořit vlastní třídy.

# Příklad A

Úkolem je napsat funkci, která rozloží cestu k souboru na jednotlivé části. 
Pomocí této funkce program otestuje cesty souborů dodané jako parametr z příkazové řádky a následně  bude  provádět porovnání s názvem spuštěného programu na základě daných kritérií. Nakonec vytiskne soubory odpovídající daným podmínkám 
(např. leží ve stejném adresáři, mají stejné jméno souboru ...).

\note Terminologie: \n
Kompletní název souboru s cestou = __cesta souboru__ = __název drivu + adresářová cesta + jméno + přípona__  ( Fully Qualified File Name = FQFN ) \n
jméno + přípona = __jméno souboru__\n
(drive + cesta = Fully Qualified Path Name = FQPN) \n
Cestu souboru předpokládáme ve zjednodušeném formátu odvozeném od Fully Portable Filename. 
To je pro cestu souboru platí: název drive je jedno písmeno a dvojtečka; oddělovačem jmen v cestě je zpětné lomítko; 
názvy obsahují písmena, číslice, podtržítko, tečku a pomlčku (nesmí být první ve jméně). 
V naší úloze bude vždy přítomno jméno souboru což je část za posledním oddělovačem. Jméno souboru nebude začínat tečkou. 
Přípona je část za poslední tečkou ve jméně souboru.

## Zadání A
Program je spuštěn s parametry na příkazovém řádku, kterými jsou jména souborů nebo cesty souborů. 
Parametr obsahuje vždy jméno souboru, a může obsahovat i cestu. Jméno souboru obsahuje jméno a příponu. Cesta obsahuje název drivu a adresářovou cestu.
Adresářová cesta vždy obsahuje oddělovač na začátku i na konci.

Úkolem je rozložit parametry na tyto jednotlivé (čtyři) části. Pokud není daná část (drive, cesta, přípona) uvedena, zůstane položka prázdná.

Na základě těchto částí se budou soubory porovnávat. V tomto příkladu je úlohou nalézt a vytisknout přípony všech souborů, které se jmenují stejně jako spuštěný program 
(první parametr v dodaných parametrech příkazového řádku), a jsou ve stejném adresáři jako on. 

Pro přehlednější ladění a manipulaci s parametry funkce \c main je ve funkci \c main připraveno pole názvů pro testování a volá se funkce \c main_A, která má stejné parametry jako \c main a při ladění tuto zastupuje.

## Upřesnění zadání




1. Pro práci s řetězci zvolte typ \c std::string, na který převeďte všechny C řetězce.
2. Pro zjištění shodnosti rozdělte cestu souboru do čtyř řetězců \c std::string - drive, cesta, jméno a přípona. 
	Alternativně zkuste použít typ \c std::string_view.
3. Tyto části (\a iDrive, \a iPath, \a iName, \a iExtension) zapouzdřete pro snadnější manipulaci do struktury \c CFilePath, 
          společně se stringem \a iOrig obsahujícím originální cestu.
4. Pokud některá část nebude ve vstupním řetězci přítomna, zůstane příslušný string prázdný.
5. První parametr na příkazové řádce (reprezentující spuštěný soubor) 
         musí obsahovat neprázdné všechny položky: drive, cesta, jméno a přípona. 
         Ostatní parametry/názvy nemusí obsahovat drive a cestu (společně). Každý název však  obsahuje neprázdnou část \a iName. 
6. Nemá-li cesta k souboru drive a cestu, má se za to že leží ve stejném adresáři jako soubor předaný prvním parametrem.
7. Přípona je část jména souboru za poslední tečkou. Jméno souboru nemusí mít příponu. V cestě nebo jméně souboru může být tečka přítomna několikrát.
8. Název drivu končí dvojtečkou. Cesta začíná a končí lomítkem. Název přípony začíná tečkou.
9. Z hlediska tisku se \c std::string chová stejně jako ostatní datové typy.



## Možný postup řešení
1. Nadefinujte strukturu obsahující \c std::string(y) pro názvy originální a odvozené: název drivu, adresáře, názvu souboru a přípony souboru
2. Vytvořte pole těchto struktur pro jednotlivé vstupní řetězce.
3. Přesuňte vstupní C řetězec do \c std::string a uložte ho do příslušné struktury.
4. Z originálního řetězce vyberte jednotlivé požadované části a uložte je do příslušných proměnných struktury (nejprve std::string, později \c std::string_view) . 
   Jako původní řetězec používejte ten uložený ve struktuře (z důvodu možného přesunu kódu z main do funkce, kde originální řetězec nebude).
5. Po zpracování proveďte kontrolu, že po složení jednotlivých získaných částí vznikne původní název.
6. Ze zadaných souborů vytiskněte přípony těch souborů, které leží ve stejném adresáři jako spuštěný soubor a mají stejné jméno jako on. 
7. Pro práci s řetězcem postupně použijte - operátor[], iterátory, rfind

## Klíčová slova pro řešení
Pro datový typ \c std::string nastudujte a využijte tyto vlastnosti:
	- \c operator= - přiřazení stringů a možnost přiřazení C řetězce
	- \c operator[] 
	- \c substr()
	- \c size()
	- \c std::string::npos - jak se používá?
	- \c rfind()
	- \c operator==, \c operator!=
	- \c empty()
	- \c find_first_not_of 
	- \c operator""s; 
	
Pro std::string_view také
	- \c remove_prefix, \c remove_postfix
	- \c operator""sv;

## Doplnění a rozšíření látky 

Ve struktuře \c CFilePath použijte \c std::string pouze pro vstupní název. Pro ostatní datové položky zvolte \c std::string_view. 
Popište k jakým změnám v programu díky tomu došlo a co se změnilo.

\note Při změně implementace původní strukturu nemažte, umožněte pomocí podmíněného překladu přepínání mezi oběmi implementacemi \c CFilePath.


# Příklad B

## Zadání B

Realizujte výpočet postfixového výrazu (RPN) za pomoci kontejneru. 
Algoritmus najdete např. na [wikipedii](https://cs.wikipedia.org/wiki/Postfixov%C3%A1_notace) v kapitole práce s postfixovou notací nebo v přednáškách ALD.


## Upřesnění zadání

- Funkce dostane jako parametr textový C řetězec, který obsahuje zápis pro výpočet v postfixovém tvaru.
- Vstupní řetězec bude obsahovat znaménka binárních operací a čísla/hodnoty (pro snazší zpracování jednociferná (tj. '0'-'9'). 
- Oddělovačem v řetězci bude mezera.
- Vstupní řetězec po znaku uložte do kontejneru typu fronta, ze kterého znaky vybírejte a zpracovávejte.
- Realizujte algoritmus zpracování (viz adresa výše).
- Vytiskněte výslednou hodnotu.


## Klíčová slova pro řešení

Na cppreference.com zjistěte význam pro následující vlastnosti:

_std::stack_ a pro něj
	- _empty_
	- _push_
	- _pop_
	- _top_

_std::queue_ a pro ni
	- _empty_
	- _push_
	- _front_
	- _pop_














