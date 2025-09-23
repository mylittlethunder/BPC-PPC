#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
//C++ je reverzne kompatibilni s C. Knihovny prelozi C stejne jako knihovny puvodni. Proto pouzivat ty optimalizovanejsi.
using namespace std;
using STDTS = timespec;
/**
\brief Zjištění času mezi dvěma okamžiky v sekundách.
*/
double difftimespec(STDTS aEnd, STDTS aBegin)
{

	return difftime(aEnd.tv_sec, aBegin.tv_sec) + (((long long)aEnd.tv_nsec - aBegin.tv_nsec) / 1000000000.0);
}

// definice typu vkládaného do kontejneru
using TYPE = double; //neco jako define v C++

// maximální počet prvků v poli náhodně generovaných čísel. CONSTEXPR - hodnota musí být spočtená už při překladu
constexpr size_t MaxLength = 50000000;
size_t vector_length = 0;
size_t list_length = 0;

int main()
{
	STDTS TimeStartVect;
	STDTS TimeEndVect;
	STDTS TimeStartList;
	STDTS TimeEndList;
	TYPE time_difference_insert_list = 0;
	TYPE time_difference_sort_list = 0;
	TYPE time_difference_insert_vector = 0;
	TYPE time_difference_sort_vector = 0;
	vector<TYPE> vect;
	list<TYPE> mylist;

	for (size_t j = 5; j < MaxLength; j *= 10)
	{
		cout << "Testing for " << j << " numbers..." << endl << endl;
		vect.clear();
		mylist.clear();
		timespec_get(&TimeStartVect, TIME_UTC);

		for(size_t i = 0; i < j; ++i)
		{
			vect.push_back(rand());
		}
		timespec_get(&TimeEndVect, TIME_UTC);
		time_difference_insert_vector = difftimespec(TimeEndVect, TimeStartVect);
		
		vector<TYPE> work_vect(vect);
		timespec_get(&TimeStartVect, TIME_UTC);
		sort(work_vect.begin(), work_vect.end(), less<TYPE>());
		timespec_get(&TimeEndVect, TIME_UTC);
		time_difference_sort_vector = difftimespec(TimeEndVect, TimeStartVect);

		timespec_get(&TimeStartList, TIME_UTC);
		
		for (size_t i = 0; i < j; ++i)
		{
			mylist.push_back(rand());
		}

		timespec_get(&TimeEndList, TIME_UTC);
		time_difference_insert_list = difftimespec(TimeEndList, TimeStartList);
		cout <<"Inserting:  "<< "Vector: " << time_difference_insert_vector << " s, " << "List: " << time_difference_insert_list << " s " << endl;
		
		list<TYPE> work_list(mylist);
		timespec_get(&TimeStartList, TIME_UTC);
		work_list.sort();
		timespec_get(&TimeEndList, TIME_UTC);
		time_difference_sort_list = difftimespec(TimeEndList, TimeStartList);
		 
		std::cout <<"Sorting - descending:  "<< "Vector: " << time_difference_sort_vector << " s, " << "List: " << time_difference_sort_list << " s " << endl << endl;
	}

	return 0;
}
