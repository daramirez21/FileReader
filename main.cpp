#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
        string fileName; //to get the name of the file to open
        string line; //to store a single line of a text file
        fstream fileStream; //to open a file for reading

        int nlines;
        int characters;
        char choice;
         
        do {
        cout<<"What file do you want to open? ";
        getline(cin, fileName);

        characters = 0;
        nlines = 0;

        fileStream.open( fileName.c_str(), ios::in );
    
        if( fileStream.is_open())
        {
                cout<<fileName<<" opened.\nFILE CONTENTS:\n";
                   
                while(!fileStream.eof())
                {
                        getline( fileStream, line);

                        if(!line.empty())
                        {
                           nlines++;
                           characters += line.length();

                           cout<<line<<endl;
                        }
                }
               
                cout<< "METADATA" << endl;
                cout<< "File: " << fileName << endl;
                cout<< "Lines: " << nlines << endl;
                cout<< "Characters: " << characters << endl;
                fileStream.close();
               
                }
                else 
                {
                 cout << fileName << " could not be opened.\n";
                 cout << "METADATA" << endl;
                 cout << "File: " << fileName << endl;
                 cout << "Lines: "<< nlines << endl;
                 cout << "Characters: " << characters << endl;
                }

                cout << "Analyze another file (y/n)? " ;
                cin >> choice;
                cin.ignore();
  
  }  while( choice== 'y' || choice == 'Y' );

    return 0;
}
