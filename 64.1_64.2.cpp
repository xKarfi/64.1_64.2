#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class klasa
{

	ifstream f1;
	ofstream f2;
	vector <string> tablica;

	public:

		klasa();
		void sprawdz();
		bool zbadaj();

};

klasa::klasa()
{
	f1.open("we.txt");
	f2.open("wy.txt");
}

void klasa::sprawdz()

{
int num_lines=0;
int num_operations=0;
string sen;
string empty_or_not;

	if(f1.good())
        {
		while(!f1.eof())
		{
			num_lines++;
			f1>>sen;


			tablica.push_back(sen);
			if(num_lines==20)

            {
        if(this->zbadaj())
			{
            num_operations++;
        	}
				num_lines=0;
				tablica.clear();

				        f1>>empty_or_not;
			}
		}
		}
	cout<<num_operations;
}
bool klasa::zbadaj()
{
	vector <string> try_another;
	for(int i=0; i<tablica.size()/2; i++)

       		{
			string pierwszy = tablica[i].substr(0, tablica[i].length()/2);
			string drugi = tablica[i].substr(tablica[i].length()/2, tablica[i].length()/2);
		
			if(pierwszy!=drugi)
			{
				return false;
			}
    	try_another.push_back(pierwszy);
			}
		int j=0;
	for(int i=tablica.size()/2; i<tablica.size(); i++)
		{
			string trzeci = tablica[i].substr(0, tablica[i].length()/2);
			string czwarty = tablica[i].substr(tablica[i].length()/2, tablica[i].length()/2);

			if(trzeci!=try_another[j] || czwarty!=try_another[j])
			{
        	return false;
			}
			j++;
		}
	return true;
}
int main(int argc, char** argv)
{
	klasa k1;
	k1.sprawdz();
	return 0;
}
