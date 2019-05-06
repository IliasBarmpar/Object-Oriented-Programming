#include "Card.hpp"

#include <fstream>
#include <cstdlib>


/*
Read Stats reads from the (fileName), untill it finds
the line (findText), then it reads the next (no_stats) lines
taking the numbers from them and inputing them in (stats[])
*/
void readStats(char *fileName, char *findText, int no_stats, int stats[]){
	ifstream inputfile;
	string line;
	int i=0,j=0;
	char input[2]; //The number will be stored here before it becomes an int

	inputfile.open(fileName);
	if(inputfile.is_open())
		while(!inputfile.eof()){
			getline(inputfile, line);

			if(line == findText){ // Finding the line we want so we can start reading
				for(int k=0; k<no_stats; k++){
                	i=0; j=0;
					input[0] = ' ';
					input[1] = ' ';
            	    getline(inputfile, line);
   					do{
						if(line[i]>='0' && line[i]<='9'){  //Taking the numbers from the line
							input[j] = line[i];
							j++;
						}
						i++;
					}while(line[i]);
					stats[k] = atoi(input);
				}
			}
	}else
	    cout << "Problem with: " << fileName  << endl;
	inputfile.close();
}

/*
int main(){

	int stats[6];

	readFile("Followers_and_Weapons.txt", "FOOTSOLDIER:", 6, stats);

	cout << stats[0] << stats[1] << stats[2] << stats[3] << stats[4] << stats[5] << endl;
}
*/
