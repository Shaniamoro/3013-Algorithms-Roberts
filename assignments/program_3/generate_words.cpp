#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;


//Determines the number of lines in the file
int numberOfLines(string filename) {
	int lines = 0;
	ifstream file(filename);
	if (file.is_open())
	{
		
		string line;
		ifstream myfile(filename);

		while (getline(myfile, line)) {
			++lines;
		}
		

	}
	return lines; 
}

int main()
{	
  int k=0;
  int l=0;
  int s=0;
  string result1;
  string result2;
  string result3;
 
  /* * Array creation
     * Creating the arrays for
     * the words to be places into them
     * */
  
	//Creates Animals array
	int numLinesAnimals = numberOfLines("../animals.txt");
	string *animals = new string[numLinesAnimals];

	//Creates Adverbs array 
	int numLinesAdverbs = numberOfLines("../adverbs.txt");
	string *adverbs = new string[numLinesAdverbs];

	//Creates Nouns array 
	int numLinesNouns = numberOfLines("../nouns.txt");
	string *nouns = new string[numLinesNouns];

	//Creates Verbs array 
	int numLinesVerbs = numberOfLines("../verbs.txt");
	string *verbs = new string[numLinesVerbs];

	//Creates Adjectives array 
	int numLinesAdjectives = numberOfLines("../adjectives.txt");
	string *adjectives = new string[numLinesAdjectives];


	//Reads data  from files into arrays 
	ifstream file("../animals.txt");
	if (file.is_open())
	{
		for (int i = 0; i < numLinesAnimals; i++) {
			file >> animals[i];
			//cout << animals[i]<<"\n";
		}
	} 
	file.close();

	ifstream file1("../adjectives.txt");
	if (file1.is_open())
	{
		for (int i = 0; i < numLinesAdjectives; i++) {
			file1 >> adjectives[i];
			//cout << adjectives[i] << "\n";
		}
	} 
	file1.close();

	ifstream file2("../adverbs.txt");
	if (file2.is_open())
	{
		for (int i = 0; i < numLinesAdverbs; i++) {
			file2 >> adverbs[i];
			//cout << adverbs[i] << "\n";
		}
	}
	file2.close();

	ifstream file3("../nouns.txt");
	if (file3.is_open())
	{
		for (int i = 0; i < numLinesNouns; i++) {
			file3 >> nouns[i];
			//cout << nouns[i] << "\n";
		}
	}
	file3.close();

	ifstream file4("../verbs.txt");
	if (file4.is_open())
	{
		for (int i = 0; i < numLinesVerbs; i++) {
			file4 >> verbs[i];
			//cout << verbs[i] << "\n";
		}
	}
	file4.close();

	//Generates random words length 3 
  
  ofstream outfile ("../tenthousandwords.txt");
  
	for (int j = 0; j <= 2500; j++) {
		if ( k < numLinesNouns && k < j) {
		  if (k % 3 == 0){
			string x = nouns[k];
			string y = animals[rand() % numLinesAnimals];
			string z = verbs[rand() % numLinesVerbs];
			result1 = x + " " + y + " "+ z ;
			outfile << result1 << endl;
		 
		} else if (k % 3 == 1){
		  string x = nouns[k];
			string y = animals[rand() % numLinesAnimals];
			string z = verbs[rand() % numLinesVerbs];
			result1 = y+ " " + z + " "+ x ;
			outfile << result1 << endl;
			
		} else {
		  string x = nouns[k];
		  string w =adjectives[rand() % numLinesAdjectives];
			string y = animals[rand() % numLinesAnimals];
			//string z = verbs[rand() % numLinesVerbs];
			result1 = w + " " + x + " "+ y;
			outfile << result1 << endl;
		}
		
		 k++;
	}
	//Creates random words of length 4 
 for (int o = 0; o <= 2500; o++) {
	 
		if ( l < numLinesAdjectives && l < o) {
			 if (l % 3 == 0){
		  string w = adjectives [l];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
			result2 = w + " " + x + " " + y + " "+ z ;
			outfile << result2 << endl;
		 
		} else if (l % 3 == 1){
		  string v = nouns [rand() % numLinesNouns];
		  string w = adjectives [l];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
			result2 = w + " " + v + " " + x + " "+ z ;
			outfile << result2 << endl;
			
		} else {
		  string v = nouns [rand() % numLinesNouns];
		  string w = adjectives [l];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
			result2 = w + " " + x + " " + v  + " "+ z ;
			outfile << result2 << endl;
		}
		  l++;
		}
	}
	// Creates random words of length 5 
	 for (int t = 0; t <= 5000; t++) {
	 
		if ( s < numLinesAdjectives && s < t) {
			 if (s % 3 == 0){
			string v = nouns [rand() % numLinesNouns];
		  string w = adjectives [s];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
			result3 = v +" " + w + " " + x + " " + y + " "+ z ;
			outfile << result3 << endl;
		 
		   } else if (s % 3 == 1){
		  string v = nouns [rand() % numLinesNouns];
		  string w = adjectives [s];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
			result3 = w  +" " + v + " " + x + " " + y + " "+ z ;
			outfile << result3 << endl;
			
	   	} else {
		  string v = nouns [rand() % numLinesNouns];
		  string w = adjectives [s];
			string x = animals[rand() % numLinesAnimals];
			string y = adverbs[rand() % numLinesAdverbs];
			string z = verbs[rand() % numLinesVerbs];
		  result3 = y +" " + z + " " + w + " " + v + " "+ x ;
			outfile << result3 << endl;
		}
		  s++;
		}
	}
	}
	outfile.close();
	
	return 0;
}






