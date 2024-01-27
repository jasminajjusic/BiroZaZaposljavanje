#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>


using namespace std;

struct Oglas{
	char imefirme[20];
	char radnomj[20];
	char str_spr[3]; //potrebna strucna sprema
	int brojmjesta;
	int radnoiskustvo; //u mjesecima
};

struct Klijent{
	char ime[10];
	char prezime[10];
	int radnoiskustvo;
	char strucnasprema[3];
};
        //pretrazivanje po vectoru(tip neki, vector<tip> vektortipova
    //genericka funk 5 6 7 i implemntacija(((()))) stoi string->int
    //iomanipi za sve ispise u zadatku 1 3 4 i delay

/*
vector<string> RazdvojiNaRijeci(string s){ //za djeljenje citavog stringa na rijeci
                                               //prekidanja razdvajanja kad dodjen do novog reda
	vector<string> v;
     int indexpocetka=0;
	for(int i=0; i<s.length(); i++){
       
        int indexrazmaka;
        if(s[i]==' ') {
            indexrazmaka=i; 
            v.push_back(s.substr(indexpocetka, indexrazmaka-indexpocetka));
            indexpocetka=indexrazmaka+1;
            i++;// da se u slj ovaj ramak preskoci, inace bi bilo beskonacno
        }

    }
    return v;
 }
   
*/

int main(){
	int odg;
	vector<Klijent>sviklijenti;
	vector<Oglas>svioglasi;
	
    ofstream izlaz1;
	izlaz1.open("TEKSTKLIJENTI.txt"); //OTVARANJE txt klijeni da se oze pisat u nju
    ofstream izlaz2;
	izlaz2.open("TEKSTOGLASI.txt");
    fstream otvaranjeklijenata; //za citanje teksta s klijentima
    fstream otvaranjeoglasa;


    int brojac678=0;
	do{	
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(90)<<setfill('*')<<right<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"NAPRAVITE ODABIR: "<<right<<"|"<<endl; //ovo kasnije mozemom iomanipom fino centar i uokvirit shu sha sitnice
		//cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"1.Ucitavanje vec postojeceg .txt fajla i nastavak rada na njemu | mozete samo na pocetku."<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"1.Unesite novog klijenta"<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"2.Unesite novi oglas"<<"|"<<endl;
		cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(90)<<setfill(' ')<<"3.Ispište nezaposlene klijente"<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(90)<<setfill(' ')<<"4.Ispišite aktivne oglase"<<"|"<<endl;
		cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(90)<<setfill(' ')<<"5.Potražite radno mjesto za ODREDENOG klijenta"<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"6.Popunite ODREDENI oglas"<<"|"<<endl;
		cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"7.Uporedite bazu oglasa i klijenata(postoji li mogucnost popuniti neko radno mjesto)"<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(89)<<setfill(' ')<<"8.KRAJ"<<"|"<<endl;
        cout<<setw(20)<<setfill(' ')<<" "<<"|"<<left<<setw(90)<<setfill('*')<<right<<"|"<<endl;
		cin>>odg;

		if(odg==8) break;
/*
        else if(odg==1){
            cout<<"Želite li upotrijebiti dokument sa informacijama o klijentima(1) ili oglasima(2)?"<<endl;
            int odgovor;
            cin>>odgovor;
            if(odgovor==1){
                    string savtekst;
                    ifstream ini_file {"dokzakopiranje.txt"}; //kopiranje iz nekog dokumenta koji cemo imenovati ovako
                    ofstream out_file {"TEKSTKLIJENTI.txt"}; //u dokument tekstklijenti koji se koristi nadalje
                    if(ini_file && out_file){
                     while(getline(ini_file,savtekst)){
                     out_file << savtekst << "\n";
                }
            cout << "Kopiranje izvrseno \n";
            } else {
                printf("Nemoguce izvrsiti kopiranje");
                 }
                 //takodjer je potrebno staviti ove stvari u vektor
           
            }
            else if(odg==2){
                     string savtekst;
                    ifstream ini_file {"dokzakopiranje.txt"};
                    ofstream out_file {"TEKSTOGLASI.txt"};
 
                    if(ini_file && out_file){
 
                     while(getline(ini_file,savtekst)){
                     out_file << savtekst << "\n";
                 }
            cout << "Kopiranje izvrseno \n";
            } else {
                printf("Nemoguce izvrsiti kopiranje");
                 }
            }
        }
        */
		else if(odg==1){
			cout<<"UNOSITE NOVOG KLIJENTA: "<<endl;
			Klijent ovaj;
			cout<<"Unesite ime: "<<endl;
			cin>>ovaj.ime;
			cout<<"Unesite prezime: "<<endl;  //e sad je ovo trebalo vako i u datpteku i u vector kako u datoteku pitam?
			cin>>ovaj.prezime;
			cout<<"Unesite radno iskustvo: (u mjesecima)"<<endl;
			cin>>ovaj.radnoiskustvo;
			cout<<"Unesite strucnu spremu (SSS / VSS / VŠS): "<<endl;
			cin>>ovaj.strucnasprema;
			izlaz1<<ovaj.ime<<" "<<ovaj.prezime<<"\nradnoiskustvo: "<<ovaj.radnoiskustvo<<" strucna sprema: "<<ovaj.strucnasprema<<"\n-----------------"<<endl; //upis u .txt
			sviklijenti.push_back(ovaj); //stavljanje u vektor za svrhe pretrazivanja
			
		}

        else if(odg==2){
			cout<<"UNOSITE NOVI OGLAS: "<<endl;
			Oglas ovaj;
			cout<<"Unesite ime firme: "<<endl;
			cin>>ovaj.imefirme;
			cout<<"Unesite radno mjesto za koje je oglas raspisan: "<<endl;  //e sad je ovo trebalo vako i u datpteku i u vector kako u datoteku pitam?
			cin>>ovaj.radnomj;
			cout<<"Unesite potrebno radno iskustvo: (u mjesecima)"<<endl;
			cin>>ovaj.radnoiskustvo;
			cout<<"Unesite potrebnu strucnu spremu (SSS / VSS / VŠS): "<<endl;
			cin>>ovaj.str_spr;
            cout<<"Unesite broj radnih mjesta: "<<endl;
			cin>>ovaj.brojmjesta;
			izlaz2<<ovaj.imefirme<<" "<<ovaj.radnomj<<"\nPOTREBNO: "<<ovaj.radnoiskustvo<<" mjeseci radnog iskustva; "<<ovaj.str_spr<<" strucna sprema; Broj mjesta: "<<ovaj.brojmjesta<<
            "\n-----------------"<<endl; //upis u .txt
			svioglasi.push_back(ovaj); //stavljanje u vektor za svrhe pretrazivanja
		}

        else if(odg==3){
            cout<<"Odabrali ste ispis nezaposlenih klijenata:"<<"\n-----------------"<<endl;
            if(sviklijenti.empty()){
                cout<<"NEMA NEZAPOSLENIH KLIJENATA."<<endl;
            }
            else if(brojac678>0){
                for(int i=0; i<sviklijenti.size(); i++){
                    cout<<sviklijenti.at(i).ime<<" "<<sviklijenti.at(i).prezime<<"\nradnoiskustvo: "<<
                    sviklijenti.at(i).radnoiskustvo<<" strucna sprema:"<<sviklijenti.at(i).strucnasprema<<"\n-----------------"<<endl;                }
            }
    
            else{
                    otvaranjeklijenata.open("TEKSTKLIJENTI.txt",ios::in); //otvaranje fajla tekstklijenti
                if (otvaranjeklijenata.is_open()){ //provjera jel otvoren
                string citavfajl;
                while(getline(otvaranjeklijenata, citavfajl)){ //citanje podataka sa njeg i stavljanje u string citavfajl
                cout << citavfajl << "\n"; //ispis string citavfajl tj ovog tekstklijenti koji je sad u tom stringu
                    }
            }
            }
            
        }

        else if(odg==4){
            cout<<"Odabrali ste ispis aktivnih oglasa:"<<"\n-----------------"<<endl;
            
            if(svioglasi.empty()){
                cout<<"NEMA AKTIVNIH OGLASA."<<endl;
            }
            else if(brojac678>0){
                for(int i=0; i<svioglasi.size(); i++){
                    cout<<svioglasi.at(i).imefirme<<" "<<svioglasi.at(i).radnomj<<"\nPOTREBNO: "<<svioglasi.at(i).radnoiskustvo<<" mjeseci radnog iskustva; "<<svioglasi.at(i).str_spr
                    <<" strucna sprema; Brojmjesta: "<<svioglasi.at(i).brojmjesta<<"\n-----------------"<<endl;
                }
            }
            else {
                        otvaranjeoglasa.open("TEKSTOGLASI.txt",ios::in); //otvaranje fajla 
                if (otvaranjeoglasa.is_open()){ //provjera jel otvoren
                string citavfajl;
                while(getline(otvaranjeoglasa, citavfajl)){ //citanje podataka sa njeg i stavljanje u string citavfajl
                cout << citavfajl << "\n"; //ispis string citavfajl tj ovog tekstklijenti koji je sad u tom stringu
                    }
                }
            }
          
            }

        else if(odg==5){

            Klijent pomocni;
            int indextrazenog;
            vector<Oglas>kojiispunjavaju;
            cout<<"Odabrali ste trazenje radnog mjesta za odredenog klijenta:"<<endl;
            cout<<"Unesite ime klijenta:"<<endl;
            char ime1[10];
            cin>>ime1;
            cout<<"Unesite prezime klijenta:";
            char prezime1[10];
            cin>>prezime1;

            brojac678++;
            for(int i=0;i<sviklijenti.size();i++){
            	if(strcmp(sviklijenti.at(i).ime,ime1)==0 && strcmp(sviklijenti.at(i).prezime,prezime1)==0){
            		 indextrazenog=i;
				}
			}
			
            int brojac=0; 

			for(int i=0;i<svioglasi.size();i++){
				Oglas ovajoglas;
                strncpy(ovajoglas.imefirme,svioglasi.at(i).imefirme,20);
                ovajoglas.radnoiskustvo=svioglasi.at(i).radnoiskustvo;  //pomocni oglas da seporedi lakse
                ovajoglas.brojmjesta=svioglasi.at(i).brojmjesta;
                strncpy(ovajoglas.str_spr, svioglasi.at(i).str_spr, 3);
                strncpy(ovajoglas.radnomj, svioglasi.at(i).radnomj, 20);

				if(strcmp(ovajoglas.str_spr,sviklijenti.at(indextrazenog).strucnasprema)==0){
					if(ovajoglas.radnoiskustvo<=sviklijenti.at(indextrazenog).radnoiskustvo){
						brojac++;
						kojiispunjavaju.push_back(ovajoglas);
					}
				}
			}

            if(brojac==0) cout<<"Klijent ne ispunjava uslove nijednog oglasa!"<<endl;
            else{

                        cout<<"Klijent ispunjava uslove "<<brojac<<" oglasa:"<<endl;
                    for(int i=0;i<brojac; i++){
                        cout<<i+1<<". oglas: ";
                                cout<<"Firma"<<kojiispunjavaju.at(i).imefirme<<" raspisuje konkurs za radno mjesto:"<<kojiispunjavaju.at(i).radnomj<<" ."<<endl;
                                cout<<"Potrebno radno iskustvo u trajanju od:"<<kojiispunjavaju.at(i).radnoiskustvo<<" mjeseci i "<<kojiispunjavaju.at(i).str_spr<<" strucnu spremu."<<endl;
                                cout<<"Uposljavamo:"<<kojiispunjavaju.at(i).brojmjesta<<endl;
                    }
                                
                        cout<<"Zelite li prijaviti klijenta na neko od radnih mjesta: D ili N"<<endl;
                        char odgovor;
                        cin>>odgovor;
                        if(odgovor=='N' || odgovor=='n'){
                            cout<<"Ne zelite zaposliti klijenta. OK"<<endl;
                        }
                        else {
                            cout<<"Redni broj radnog mjesta na koji zaposljavate klijenta:"<<endl;
                            int br;
                            cin>>br;
                            int indexusvimoglasima;
                            for(int i=0; i<svioglasi.size(); i++){
                                if(strcmp(svioglasi.at(i).imefirme,kojiispunjavaju.at(br-1).imefirme)==0 &&
                                strcmp(svioglasi.at(i).radnomj,kojiispunjavaju.at(br-1).radnomj)==0){
                                    indexusvimoglasima=i;
                                    break;
                                }
                            }
                        cout<<"Uposlili ste klijenta na radno mjesto:"<<kojiispunjavaju.at(br-1).radnomj<<" firme:"<<kojiispunjavaju.at(br-1).imefirme<<endl;
                        kojiispunjavaju.at(br-1).brojmjesta--;
                        sviklijenti.erase(sviklijenti.begin()+ indextrazenog);
                        if(kojiispunjavaju.at(br-1).brojmjesta==0){
                            svioglasi.erase(svioglasi.begin()+ indexusvimoglasima); //brise se oglas koji je popunjen ako je dosao na 0 ttrazeni radnih mjesta
                            
                        }		
				}
            }
            
        }

        else if(odg==6){
            cout<<"Odabrali ste upopunjavanje upraznjenog radnog mjesta na odredjenom oglasu."<<endl;
            cout<<"Unesite ime firme: "<<endl;
            char ime[20];
            cin>>ime;
            cout<<"Unesite naziv radnog mjesta: "<<endl;
            char radno[20];
            cin>>radno;
            brojac678++;
            int trazenomj;
            for(int i=0; i<svioglasi.size(); i++){ //pronalazi oglas u vektoru oglasa
                if(strcmp(ime,svioglasi.at(i).imefirme)==0 && strcmp(radno, svioglasi.at(i).radnomj)==0){
                    trazenomj=i;
                }
            }

            Oglas pomocnioglas;
             strncpy(pomocnioglas.imefirme,svioglasi.at(trazenomj).imefirme,20);
            pomocnioglas.radnoiskustvo=svioglasi.at(trazenomj).radnoiskustvo;  //pomocni oglas da seporedi lakse
            pomocnioglas.brojmjesta=svioglasi.at(trazenomj).brojmjesta;
            strncpy(pomocnioglas.str_spr, svioglasi.at(trazenomj).str_spr, 3);
            strncpy(pomocnioglas.radnomj, svioglasi.at(trazenomj).radnomj, 20);

            vector<Klijent>ispunjavajuuslove;
            int brojac=0;

            for(int i=0; i<sviklijenti.size(); i++){
                if(pomocnioglas.radnoiskustvo<=sviklijenti.at(i).radnoiskustvo && strcmp(pomocnioglas.str_spr, sviklijenti.at(i).strucnasprema)==0){
                    ispunjavajuuslove.push_back(sviklijenti.at(i));
                    brojac++;
                }
            }

            if(brojac==0) cout<<"Niko od vasih klijenata ne ispunjava uslove ovog oglasa"<<endl;
            else{

                      cout<<"Klijenti koji ispunjavaju uslove oglasa: "<<endl;

            for(int j=0; j<ispunjavajuuslove.size(); j++){
                cout<<j+1<<". "<<ispunjavajuuslove.at(j).ime<<" "<<ispunjavajuuslove.at(j).prezime<<" sa "
                <<ispunjavajuuslove.at(j).radnoiskustvo<<" mjeseci radnog iskustva i "<<ispunjavajuuslove.at(j).strucnasprema<<" strucnom spremom."<<endl;
            }

            cout<<"Zelite li zaposliti ijednog od njih na navedeno radno mjeseto? D/N "<<endl;
            char odg1;
            cin>>odg1;
            if(odg1=='N' || odg1=='n'){
                cout<<"Ne zelite zaposliti nikog od navedenih na ovo radno mjesto. OK.";
            }
            else{
                cout<<"Unesite redni broj klijenta kojeg zelite zaposliti:";
                int redni;
                cin>>redni;
                cout<<"Uposlili ste klijenta: "<<ispunjavajuuslove.at(redni-1).ime<<" "<<ispunjavajuuslove.at(redni-1).prezime<<
                " na radno mjesto "<<pomocnioglas.radnomj<<" firme "<<pomocnioglas.imefirme<<endl;   

                int indextrazenog;
                     for(int i=0;i<sviklijenti.size();i++){
            	if(strcmp(sviklijenti.at(i).ime,ispunjavajuuslove.at(redni).ime)==0 && strcmp(sviklijenti.at(i).prezime,ispunjavajuuslove.at(redni).prezime)==0){
            		 indextrazenog=i;
				        }
			        }
                    sviklijenti.erase(sviklijenti.begin()+ indextrazenog);

                pomocnioglas.brojmjesta--;
				if(pomocnioglas.brojmjesta==0){
					svioglasi.erase(svioglasi.begin()+ trazenomj); //brise se oglas koji je popunjen ako je dosao na 0 ttrazeni radnih mjesta
					
				}		
			 }
        }
        }

        else if(odg==7){
             cout<<"Odabrali ste uporedjivanje baze oglasa i klijenata:"<<endl;
             int brojac=0;
             brojac678++;
            for(int i=0;i<svioglasi.size();i++){
            	for(int j=0;j<sviklijenti.size();j++){
            		if(strcmp(sviklijenti.at(j).strucnasprema,svioglasi.at(i).str_spr)==0 && sviklijenti.at(j).radnoiskustvo>=svioglasi.at(i).radnoiskustvo){
                        brojac++; //ovaj brojac se samo koristi za ispis ukoliko se ni a jedno radno mjeto ne nadje niko
            			cout<<"Uslove konkursa firme "<<svioglasi.at(i).imefirme<<" za radno mjesto: "<<svioglasi.at(i).radnomj<<" ispunjava "<<sviklijenti.at(j).ime<<" "<<sviklijenti.at(j).prezime<<endl;
            			cout<<"Zelite li ga zaposliti?"<<endl;
						char odg5;
						cin>>odg5;
						if(odg5=='n' || odg5=='N'){
							cout<<"Uredu,ne zelite zaposliti klijenta."<<endl;
						}
						else{
							cout<<"Uposlili ste"<<sviklijenti.at(j).ime<<" "<<sviklijenti.at(j).prezime<<" "<<"na radno mjesto"<<" "<<svioglasi.at(i).radnomj<<" "<<"firme "<<svioglasi.at(i).imefirme<<endl;
							
                            sviklijenti.erase(sviklijenti.begin()+ j);
                            svioglasi.at(i).brojmjesta--;

                            if(svioglasi.at(i).brojmjesta==0){
					svioglasi.erase(svioglasi.begin()+ i); //brise se oglas koji je popunjen ako je dosao na 0 ttrazeni radnih mjesta
					
				            }		
						}	
						}
					}
				}
                if(brojac==0) cout<<"Ni za jedno radno mjesto nema nijedan klijent sa potrebnim kvalifikacijama."<<endl;
        }

		
	}while(1); //beskonacna do breaka
	
    izlaz1.close(); //fajlovi se zatvaraju (DA LI IH POD ODG (?? PITAM) kasnije probat)
    izlaz2.close();
    otvaranjeklijenata.close();

	return 0;
}

/* samo za ispitivanje funk izdvoji na rijeci
int main(){
    string s;
    cin>>s;
    vector<string> rijeci;
    RazdvojiNaRijeci(s, rijeci);
    for(int i=0; i<rijeci.size(); i++){
        cout<<rijeci.at(i)<<endl;
    }
    return 0;
}*/