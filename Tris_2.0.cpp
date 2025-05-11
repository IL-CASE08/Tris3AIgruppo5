#include <iostream>
#include <cstdlib> //ABBIAMO USATO QUESTA LIBRERIA PER RANDOMIZZARE GIOCATORI
#include <ctime> //ABBIAMO USATO QUESTA LIBRERIA  PER RANDOMIZZARE GIOCATORI
using namespace std;



bool GameOver=false;
int Contatore,ContaX,ContaO,numero,primoGiocatore;
char segno_X,segno_O,Risultato;
bool controllo;
string Giocatore1,Giocatore2;
char Tris[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

// ABBIAMO CREATO QUESTA FUNZIONE PER CREARE LA GRIGLIA DI GIOCO
void Campo_di_Gioco(const char Tris[])  {  //PASSO UN ARRAY CON VALORI COSTANTI IN QUANTO NON DEVE ESSERE MODIFICATO
    cout << "----------------" << endl;    
    for (int i = 0; i < 9; ++i) {
        cout <<i<<"| " << Tris[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "|" << endl;
            cout << "----------------" << endl;
        }
    }
}
bool VerificaCampo(int numero,char Tris[]){

    if(Tris[numero]=='X'||Tris[numero]=='O'){
        cout <<"E' GIA OCCUPATO INSERISCI NUOVO NUMERO "<<endl;
        return false;
    } else{

        return true;
    }
}
/*UTILIZZIAMO LA FUNZIONE GIOCA PER DEI CONTROLLI E PER INSERIRE LA 'X' O LO 'O' SUL CAMPO DI GIOCO
ALL'INTERNO CHIAMIAMO LA FUNZIONE VERIFICA CAMPO CHE CI PERMETTE DI VERIFICARE SE LA POSIZIONE SCELTA DAL GIOCATORE 
ERA GIA STATA SCELTA IN PRECEDENZA*/
bool Gioca(int numero,char Tris[],char segno){
   if (VerificaCampo(numero,Tris)){
    Tris[numero]=segno;
        return true;
   }else{

    return false;
   }
}

char VerificaVittoria(const char Tris[]) {
    //QUA CONTROLLIAMO SE  CE' UN TRIS SULLE RIGHE 
    for (int i = 0; i < 9; i += 3) {
        if (Tris[i] == Tris[i + 1] && Tris[i + 1] == Tris[i + 2] && Tris[i] != ' ') {
            return Tris[i];
        }
    }

    //QUA CONTROLLIAMO SE  CE' UN TRIS SULLE COLONNE
    for (int i = 0; i < 3; ++i) {
        if (Tris[i] == Tris[i + 3] && Tris[i + 3] == Tris[i + 6] && Tris[i] != ' ') {
            return Tris[i];
        }
    }

    //QUA CONTROLLIAMO SE  CE' UN TRIS SULLE DIAGONALI
    if ((Tris[0] == Tris[4] && Tris[4] == Tris[8] && Tris[0] != ' ') ||
        (Tris[2] == Tris[4] && Tris[4] == Tris[6] && Tris[2] != ' ')) {
        return Tris[4];
    }

    //QUA CONTROLLIAMO SE CE UN PAREGGIO
    for (int i = 0; i < 9; ++i) {
        if (Tris[i] == ' ') {
            return ' '; //VERIFICA SE CI SONO ANCORA SPAZI VUOTI
        }
    }

    return 'P'; //IN CASO NON CI SONO NE VINCITORI NE SPAZI VUOTI CI INDICA SE E' PAREGGIO
}

/*QUESTA FUNZIONE E' LA FUNZIONE PRINCIPALE DELLA PARTITA ALLA QUALE PASSIAMO IL NUMERO DI PARTITE TOTALI,LA VARIABILE CHE 
PERMETTE DI FINIRE LA PARTITA,LA VARIABILE RANDOMIZZATA DELLA SCELTA DEL PRIMO GIOCATORE E LA GRIGLIA DI GIOCO PULITA,LE VARIABILI 
PASSATE PER RIFERIMENTO CI PERMETTONO DI MODIICARE DIRETTAMENTE LA VARIABILE SENZA RITORNARLA,QUELLA PRIMO GIOCATORE CI PERMETTE COSI' 
L'ALTERNANZA ANCHE A INIZIO PARTITA (NON OBBLIGATORIA) */
void iniziopartita (int contatore, bool &GameOver ,int &primoGiocatore, char Tris[]){ 
    GameOver = false; //RIMETTE FALSE PER RICOMINCIARE LA PARTITA
    cout << "QUESTA E' LA PARTITA NUMERO " << contatore+1 <<endl;

    while(!GameOver){

        if (primoGiocatore ==0) {
            cout <<"E' IL TURNO DI "<< Giocatore1 <<" GIOCATORE DELLE X E INSERISCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            while (!Gioca(numero,Tris,segno_X)){
              cout <<"E' IL TURNO DI "<< Giocatore1 <<" GIOCATORE DELLE X E INSERISCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            };

            Risultato=VerificaVittoria(Tris); //SERVE PER VERIFICARE SE CE UN VINCITORE
            if(Risultato== 'X'){
              Contatore+=1;
              ContaX +=1;
              cout<<"il giocatore "<< Giocatore1 <<" delle X ha vinto!"<<endl;
              GameOver=true;
            }if(Risultato=='P'){
              cout<<"LA PARTITA E' FINITA IN PAREGGIO!"<<endl; //LA PARTITA PAREGGIATA NON LA CONTIAMO
              GameOver=true;
            }
            Campo_di_Gioco(Tris);
            primoGiocatore=1; //CI PERMETTE DI ALTERNARE I GIOCATORI
        } else {
            cout <<"E' IL TURNO DI "<< Giocatore2 <<" GIOCATORE DELLE O E INSERSCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            while (!Gioca(numero,Tris,segno_O)){
              cout <<"E' IL TURNO DI "<< Giocatore2 <<" GIOCATORE DELLE O E INSERSCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            };
            Risultato=VerificaVittoria(Tris); //SERVE PER VERIFICARE SE CE UN VINCITORE
            if(Risultato== 'O'){
              Contatore+=1;
              ContaO +=1;
              cout<<"il giocatore "<< Giocatore2 <<" delle O ha vinto!"<<endl;
              GameOver=true;
            }if(Risultato=='P'){
              cout<<"LA PARTITA E' FINITA IN PAREGGIO!"<<endl; //LA PARTITA PAREGGIATA NON LA CONTIAMO
              GameOver=true;
            }
            Campo_di_Gioco(Tris);
            primoGiocatore=0; //CI PERMETTE DI ALTERNARE I GIOCATORI
        }
       }


}




int main(){
    
    segno_X='X';
    segno_O='O';
    //I CONTATORI LI UTILIZZIAMO PER CONTARE LE VITTORIE E LE PARTITE DA GIOCARE
    Contatore=0;
    ContaX=0;
    ContaO=0;
    cout<<"Giocatore 1 inserisci il tuo nome :";
    cin>>Giocatore1;
    cout<<"Giocatore 2 inserisci il tuo nome :";
    cin>>Giocatore2;
    //FACCIAMO SCEGLIERE A CASO CHI INIZIA A GIOCARE
    srand(time(0));
    primoGiocatore =rand() % 2;
    //LA PARTITA E' AL MEGLIO DI 3/5
    while(Contatore<5){
            // PULISCE IL CAMPO DA GIOCO AD OGNI PARTITA
        char Tris[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
        Campo_di_Gioco(Tris);   //CHIAMO LA FUNZIONE CAMPO DI GIOCO CHE MOSTRA AI GIOCATORI LA GRIGLIA DEL TRIS

        if (ContaX==3){  //L'IF CONTA LE PARTITE VINTE ARRIVATE A TRE SI VINCE LO SCONTRO
        cout<< "hai vinto giocatore numero 1 "<<Giocatore1 << endl;
        break;   //ESCE DAL  CICLO QUANDO IL GIOCATORE HA VINTO 3 VOLTE
        }
        if (ContaO==3){
        cout<< "hai vinto giocatore numero 2 "<<Giocatore2 << endl;
        break;  //ESCE DAL  CICLO QUANDO IL GIOCATORE HA VINTO 3 VOLTE
        }
        iniziopartita (Contatore,GameOver,primoGiocatore,Tris); //CHIAMO LA FUNZIONE CHE CI PERMETTE DI INIZIARE UNA PARTITA

    }

    system("PAUSE");
    return 0;
}