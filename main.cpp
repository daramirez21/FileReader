#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
    char choice = 'y';

    do {

        string fileName; //to get the name of the file to open
        string line; //to store a single line of a text file
        fstream fileStream; //to open a file for reading

        int nlines;
        int characters;

        nlines = 0;
        characters = 0;  

        cout<<"What file do you want to open? ";
        getline(cin, fileName);

        //STEP 1: open the fileStream for input, using the fileName specified

        fileStream.open( fileName.c_str(), ios::in );
 
        if( fileStream.is_open() )
        {
                cout<<fileName<<" opened.\nFILE CONTENTS:\n";

                while (!fileStream.eof() )
                {

                        getline( fileStream, line);

                        if(!line.empty() )
                        {

                                cout << line << endl;

                                nlines = nlines + 1;
                                        
                                characters = characters + line.length();
                        }

                }

                cout << "METADATA" << endl;

                cout << "File: " << fileName << endl;

                cout << "Lines: "<< nlines << endl;

                cout << "Characters: " << characters << endl;

                cout << "Analyze another file (y/n)? " << endl;
                cin >> choice;
                cin.ignore();

                  }
 
        else
        {
                cout << fileName <<" could not be opened.\n";
                cout << "METADATA" << endl;
                cout << "File: " <<fileName<<endl;
                cout << "Lines: " <<nlines << endl;
                cout << "Characters: " <<characters<<endl;
                cout << "Analyze another file (y/n)? " <<endl;
                cin >> choice;
                cin.ignore();
                         
         }
  }  while( choice=='y' || choice == 'Y' );

    return 0;
}
