#include<iostream>
#include<fstream>
using namespace std;
void readdata(string &alphabets);
void missing(string alphabets);

int main(){

    string alphabets;

    missing(alphabets);

    return 0;

}
void missing(string alphabets){

    readdata(alphabets);
    string missletters="";

    for(int i=97;i<=122;i++){

    char x=i;
    bool found=false;

    for(int j=0;alphabets[j]!='\0';j++){
         if(alphabets[j]==x){
            found=true;
            break;
         }
    }

         if(!found){
            missletters += x;
         }   
    }

    fstream file;
    file.open("alphabets.txt",ios::app);
    file<<missletters<<endl;
    file.close();

    cout<< "The missing letters have been appended to alphabets.txt"<<endl;

}
void readdata(string &alphabets){

    fstream file;
    string line;

    file.open("alphabets.txt",ios::in);
    while(getline(file,line)){
        alphabets += line;
    }

    file.close();

}