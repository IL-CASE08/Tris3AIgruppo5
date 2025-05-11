#include <iostream>
#include <cstdlib> //ABBIAMO USATO QUESTA LIBRERIA PER RANDOMIZZARE GIOCATORI
#include <ctime> //ABBIAMO USATO QUESTA LIBRERIA  PER RANDOMIZZARE GIOCATORI
using namespace std;


char Risultato;
bool GameOver=false;
int Contatore,ContaX,ContaO;
char segno_X,segno_O;
int numero,primoGiocatore;
bool controllo;
string Giocatore1,Giocatore2;
char Tris[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

// ABBIAMO CREATO QUESTA FUNZIONE PER CREARE LA GRIGLIA DI GIOCO
void Campo_di_Gioco(const char Tris[])  {
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
bool Gioca(int numero,char Tris[],char segno){
   if (VerificaCampo(numero,Tris)){
    Tris[numero]=segno;
        return true;
   }else{

    return false;
   }
}

char VerificaVittoria(const char Tris[]) {
    // Controlla le righe
    for (int i = 0; i < 9; i += 3) {
        if (Tris[i] == Tris[i + 1] && Tris[i + 1] == Tris[i + 2] && Tris[i] != ' ') {
            return Tris[i];
        }
    }

    // Controlla le colonne
    for (int i = 0; i < 3; ++i) {
        if (Tris[i] == Tris[i + 3] && Tris[i + 3] == Tris[i + 6] && Tris[i] != ' ') {
            return Tris[i];
        }
    }

    // Controlla le diagonali
    if ((Tris[0] == Tris[4] && Tris[4] == Tris[8] && Tris[0] != ' ') ||
        (Tris[2] == Tris[4] && Tris[4] == Tris[6] && Tris[2] != ' ')) {
        return Tris[4];
    }

    // Controlla se c'è un pareggio
    for (int i = 0; i < 9; ++i) {
        if (Tris[i] == ' ') {
            return ' '; // Ci sono ancora spazi vuoti
        }
    }

    return 'P'; // Pareggio
}

void iniziopartita (int contatore, bool &GameOver ,int &primoGiocatore, char Tris[]){ // Passa Tris per riferimento
    GameOver = false; // Reinizializza GameOver all'inizio di ogni partita
    cout << "QUESTA E' LA PARTITA NUMERO " << contatore+1 <<endl;

    while(!GameOver){

        if (primoGiocatore ==0) {
            cout <<"E' IL TURNO DI "<< Giocatore1 <<" GIOCATORE DELLE X E INSERISCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            while (!Gioca(numero,Tris,segno_X)){
              cout <<"E' IL TURNO DI "<< Giocatore1 <<" GIOCATORE DELLE X E INSERISCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            };

            Risultato=VerificaVittoria(Tris);
            if(Risultato== 'X'){
              Contatore+=1;
              ContaX +=1;
              cout<<"il giocatore "<< Giocatore1 <<" delle X ha vinto!"<<endl;
              GameOver=true;
            }if(Risultato=='P'){
              cout<<"la partita e' finita in pareggio"<<endl;
              GameOver=true;
            }
            Campo_di_Gioco(Tris);
            primoGiocatore=1;
        } else {
            cout <<"E' IL TURNO DI "<< Giocatore2 <<" GIOCATORE DELLE O E INSERSCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            while (!Gioca(numero,Tris,segno_O)){
              cout <<"E' IL TURNO DI "<< Giocatore2 <<" GIOCATORE DELLE O E INSERSCI UN NUMERO DA (0 A 8): ";
            cin>>numero;
            };
            Risultato=VerificaVittoria(Tris);
            if(Risultato== 'O'){
              Contatore+=1;
              ContaO +=1;
              cout<<"il giocatore "<< Giocatore2 <<" delle O ha vinto!"<<endl;
              GameOver=true;
            }if(Risultato=='P'){
              cout<<"la partita e' finita in pareggio"<<endl;
              GameOver=true;
            }
            Campo_di_Gioco(Tris);
            primoGiocatore=0;
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
        Campo_di_Gioco(Tris);//CHIAMO LA FUNZIONE CAMPO DI GIOCO CHE MOSTRA AI GIOCATORI LA GRIGLIA DEL TRIS

        if (ContaX==3){//L'IF CONTA LE PARTITE VINTE ARRIVATE A TRE SI VINCE LO SCONTRO
        cout<< "hai vinto giocatore numero 1 "<<Giocatore1 << endl;
        break; //ESCE DAL  CICLO QUANDO IL GIOCATORE HA VINTO 3 VOLTE
        }
        if (ContaO==3){
        cout<< "hai vinto giocatore numero 2 "<<Giocatore2 << endl;
        break;  //ESCE DAL  CICLO QUANDO IL GIOCATORE HA VINTO 3 VOLTE
        }
        iniziopartita (Contatore ,GameOver,primoGiocatore, Tris); //CHIAMO LA FUNZIONE CHE CI PERMETTE DI INIZIARE UNA PARTITA

    }

    system("PAUSE");
    return 0;
}