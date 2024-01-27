#include <iostream>
#include <string>
#include <cstring>
#include<string.h>
#include <vector>
#include <iomanip>
#include <fstream>


using namespace std;

vector<string> RazdvojiNaRijeci(string s){ //za djeljenje citavog stringa na rijeci
                                               //prekidanja razdvajanja kad dodjen do novog reda
	vector<string> v;
    int indexpocetka=0;
    int indexrazmaka;
	for(int i=0; i<s.length(); i++){
       
        if(s[i]==' ') {  
            indexrazmaka=i; 
            string prim=s.substr(indexpocetka, indexrazmaka-indexpocetka);
            v.push_back(prim);
            indexpocetka=indexrazmaka+1;
            i++;// da se u slj ovaj ramak preskoci, inace bi bilo beskonacno
        }

    }
    return v;
 }
   


int main(){
    string s;
    cin>>s;
    vector<string> rijeci=RazdvojiNaRijeci(s);
    for(int i=0; i<rijeci.size(); i++){
        cout<<rijeci.at(i)<<endl;
    }
    return 0;}