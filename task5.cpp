#include<iostream>
#include<fstream>
using namespace std;
string contomorse();
char alpha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-.-.-.-"};


int main(){

    string res=contomorse();
    cout<<"Morse code: "<<res<<endl;

    fstream outfile;
    outfile.open("convertedtomorse.txt",ios::out);
    outfile<<res;

    outfile.close();

    cout << "Morse code has also been written to 'convertedtomorse.txt'" << endl;

    return 0;
}

string contomorse(){

     string line;
     fstream file;
     string mor="";
     int idx;

    file.open("morse.txt",ios::in);
    
    while(getline(file,line)){
        for(int i=0;i<line.length();i++){

            char c=line[i];

              if(c>='a' && c<='z'){
                c=c-('a'-'A');
              }
              if(c>='A' && c<='Z'){
                idx=c-'A';
                mor += morse[idx]+" ";
                }
                else if (c == ' ') {
                mor += morse[26] + " "; 
            }
        }
}
file.close();
return mor;
}
