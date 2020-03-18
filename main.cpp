#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct nod
{
    char info;
    nod *next;
};

class stiva
{
private:
    nod *top; ///membru privat pentru varful stivei
protected:
public:
    stiva()
    {
        top=NULL;   ///constructor initializare vf stivei
    }
    stiva(stiva &st);
    void push(); ///metoda publica pentru adaugare element
    void pop(); ///metoda publica pentru stergere element
    void topp(); ///metoda publica afisarea varfului stivei
    void isEmpty(); ///metoda publica pentru a testa daca stiva e vida
    friend istream &operator>>(istream &in, stiva &st); ///supraincarcare >>
    friend ostream &operator<<(ostream &out, stiva &st); ///supraincarcare <<
    stiva operator-(const stiva &st); ///supraincarcare -
};

void stiva::push()  ///introducerea de elemente
{
    nod *aux;
    aux=new nod;
    cout<<"Introduceti elementul:";
    cin>>aux->info;
    aux->next=top;
    top=aux;
}

void stiva::pop()  ///stergerea elementului din varf
{
    nod *aux=top;
    top=top->next;
    cout<<"Am sters: "<<aux->info;
    delete aux;
}

void stiva::topp() ///ne este afisat varful stivei
{
    nod*aux=top;
    cout<<aux->info;
}

void stiva::isEmpty()   ///scurta verificare daca stiva este goala
{
    if(top!=NULL)
        cout<<"Stiva nu este goala.";
    else
        cout<<"Stiva este goala.";
}

istream &operator>>(istream &in, stiva &st)
{
///aici am INCERCAT sa supraincarc operatorul >>
    nod *aux=st.top;
    while(aux!=NULL)
    {
        in>>aux->info;
        aux=aux->next;

    }
    return in;
}

ostream &operator<<(ostream &out, stiva &st)
{
///aici am REUSIT sa supraincarc operatorul <<
    nod *aux=st.top;
    while(aux!=NULL)
    {
        cout<<aux->info<<" ";
        aux=aux->next;
    }
    while(st.top!=NULL)
    {
        nod*aux=st.top;
        st.top=st.top->next;
        delete aux;
    }
    return out;
}
stiva stiva::operator-(const stiva &st)
{
///am incercat diferite metode, dar n-am reusit sa
///o scot la capat in timp util..
}
void menu_output()
{
    cout<<"\n Metesan Raul Petru - 211 - Tema 4 - Stiva de caractere\n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste prima stiva:"<<endl;
    cout<<"2. Citeste a doua stiva:"<<endl;
    cout<<"3. Adaugare element nou in stiva"<<endl;
    cout<<"4. Stergere element din stiva"<<endl;
    cout<<"5. Afisare varf stiva"<<endl;
    cout<<"6. Este goala stiva?"<<endl;
    cout<<"7. Afisare Stiva"<<endl;
    cout<<"0. Iesire."<<endl;
}

int main()
{
    int i,n,option;///optiunea aleasa din meniu
    option=0;
    stiva st1,st2;
    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            cout<<"Numarul de elemente din stiva: ";
            cin>>n;
            for(i=1; i<=n; i++)
                st1.push();
        }
        if (option==2)
        {
            cout<<"Numarul de elemente din stiva: ";
            cin>>n;
            for(i=1; i<=n; i++)
                st2.push();
        }
        if (option==3)
        {
            st1.push();
        }
        if (option==4)
        {
            st1.pop();
        }
        if (option==5)
        {
            st1.topp();
        }
        if (option==6)
        {
            st1.isEmpty();
        }
        if (option==7)
        {
            cout<<st1;
        }
        if (option==0)
        {
            cout<<"EXIT";
        }
        if (option<0||option>7)
        {
            cout<<"ABNORMAL PROGRAM TERMINATION";
        }
        cout<<endl;
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);

}

