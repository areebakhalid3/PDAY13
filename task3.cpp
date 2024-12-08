#include<iostream>
#include<fstream>
using namespace std;
void cake(int &idx,int age[],string name[]);
string getfield(string line,int field);

main(){

    string name[100];
    int age[100];
     fstream file;
     int idx=0;

     cake(idx,age,name);
      fstream outfile;
       outfile.open("ck.txt",ios::out);

     for(int i=0;i<idx;i++){

     if(age[i]%2==0){
        outfile<<"###############"<<endl;
        outfile<<"# "<<age[i]<<" HB "<<name[i]<<"! "<<age[i]<<" #"<<endl; 
        outfile<<"###############"<<endl;
    }
    else{
        outfile<<"***************"<<endl;
        outfile<<"* "<<age[i]<<" HB "<<name[i]<<"! "<<age[i]<<" *"<<endl; 
        outfile<<"***************"<<endl;
    }
}
    outfile.close();

     cout << "Birthday cake messages have been written to ck.txt"<<endl;
}
void cake(int &idx,int age[],string name[]){

     string line;
     fstream file;

    file.open("names.txt",ios::in);
    
    while(getline(file,line)){
    name[idx]=getfield(line,1);
    age[idx]=stoi(getfield(line,2));
    idx++;
}
file.close();
}

string getfield(string line,int field){

    int commacount=1;
    string item;

      for(int i=0;i<line.length();i++){

        if(line[i]==','){
            commacount = commacount+1;
        }
        else if(commacount==field){
            item=item+line[i];
        }
    }
    return item;
}