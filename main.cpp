#include <iostream>

using namespace std;


struct Koral
{
    short id_korala = 0;
    char id_sznura[3] ;

    Koral* prev = nullptr;
    Koral* next = nullptr;

};



struct Lista_Korali
{
    Koral* poczatek= nullptr;
    Koral* koniec = nullptr;
    Koral* temp = nullptr;
    Koral* temp_2 = nullptr;

    int dlg_listy = 0;

    void add_wiazanie_do_korala( Koral* k1 )
    {

        temp = koniec ;

        if ( poczatek == nullptr )
        {


            poczatek = new Koral;
            koniec = poczatek;
            temp = poczatek;

            poczatek->id_sznura[0] = k1->id_sznura[0] ;
            poczatek->id_sznura[1] = k1->id_sznura[1] ;
            poczatek->id_sznura[2] = k1->id_sznura[2] ;

            poczatek->id_korala = k1->id_korala;

            poczatek->next = nullptr;

            dlg_listy = 1;

        } else
        {

            while ( (k1->id_sznura < temp->id_sznura)  )
            {
                temp = temp->prev;

            }

            if ( temp == nullptr )
            {


                poczatek->prev = new Koral;
                poczatek->prev->id_sznura[0] = k1->id_sznura[0] ;
                poczatek->prev->id_sznura[1] = k1->id_sznura[1] ;
                poczatek->prev->id_sznura[2] = k1->id_sznura[2] ;
                poczatek->prev->id_korala = k1->id_korala ;
                poczatek->prev->next = poczatek;
                poczatek = poczatek->prev ;



            } else if ( (k1->id_sznura > temp->id_sznura) )
            {

                temp = koniec;

                koniec->next = new Koral;
                koniec = koniec->next ;
                koniec->id_sznura[0] = k1->id_sznura[0] ;
                koniec->id_sznura[1] = k1->id_sznura[1] ;
                koniec->id_sznura[2] = k1->id_sznura[2] ;
                koniec->id_korala = k1->id_korala ;
                koniec->prev = temp;

            } else
            {

                while ( temp->id_korala > k1->id_korala )
                {
                    temp = temp->prev ;
                }

                if ( temp == nullptr )
                {


                    poczatek->prev = new Koral;
                    poczatek->prev->id_sznura[0] = k1->id_sznura[0] ;
                    poczatek->prev->id_sznura[1] = k1->id_sznura[1] ;
                    poczatek->prev->id_sznura[2] = k1->id_sznura[2] ;
                    poczatek->prev->id_korala = k1->id_korala ;
                    poczatek->prev->next = poczatek;
                    poczatek = poczatek->prev ;

                } else if ( temp->id_korala < k1->id_korala  )
                {


                    temp = koniec;

                    koniec->next = new Koral;
                    koniec = koniec->next ;
                    koniec->id_sznura[0] = k1->id_sznura[0] ;
                    koniec->id_sznura[1] = k1->id_sznura[1] ;
                    koniec->id_sznura[2] = k1->id_sznura[2] ;
                    koniec->id_korala = k1->id_korala ;
                    koniec->prev = temp;

                } else
                {

                    temp_2 = temp->next ;

                    temp->next = new Koral;
                    temp->next->prev = temp;

                    temp_2->prev = temp->next;
                    temp_2->prev->next = temp_2;

                    temp = temp->next ;

                    temp->id_sznura[0] = k1->id_sznura[0] ;
                    temp->id_sznura[1] = k1->id_sznura[1] ;
                    temp->id_sznura[2] = k1->id_sznura[2] ;
                    temp->id_korala = k1->id_korala ;


                }


            }


        }

        dlg_listy += 1 ;

    }


    void delete_wiazanie_korala()
    {


    }


};


struct Koral_z_wiazaniami
{

    Koral_z_wiazaniami* prev;
    Koral_z_wiazaniami* next;

    Koral* Koral;
    Lista_Korali* Lista_Korali;

};

struct Sznur
{

    Sznur* next;
    Sznur* prev;

    char id_sznura[3];

    int ile_korali = 0;

    Koral_z_wiazaniami* first ;
    Koral_z_wiazaniami* last;
    Koral_z_wiazaniami* temp;




};


struct Struktura
{
    int ile_sznurow = 0;

    Sznur* first ;
    Sznur* last ;
    Sznur* temp ;
    Sznur* temp_2 ;

    void add_sznur( char sn[] )
    {

        if ( first == nullptr )
        {
            first = new Sznur;
            first->id_sznura[0] = sn[0] ;
            first->id_sznura[1] = sn[1] ;
            first->id_sznura[2] = sn[2] ;

            last = first;


        } else
        {


            temp = last ;
            while ( temp->id_sznura > sn )
            {
                temp = temp->prev;
            }

            if ( temp == nullptr )
            {
                first->prev = new Sznur;
                first->prev->next = first;
                first = first->prev ;

                first->id_sznura[0] = sn[0] ;
                first->id_sznura[1] = sn[1] ;
                first->id_sznura[2] = sn[2] ;

            } else if ( (temp->id_sznura < sn) && (temp == last) )
            {
                temp->next = new Sznur;
                temp->next->prev = temp ;
                last = temp->next ;

                last->id_sznura[0] = sn[0] ;
                last->id_sznura[1] = sn[1] ;
                last->id_sznura[2] = sn[2] ;

            } else
            {

                temp_2 = temp->next ;
                temp->next = new Sznur;
                temp->next->prev = temp;

                temp_2->prev = temp->next;
                temp_2->prev->next =  temp_2 ;

                temp = temp->next ;

                temp->id_sznura[0] = sn[0] ;
                temp->id_sznura[1] = sn[1] ;
                temp->id_sznura[2] = sn[2] ;

            }


        }

    }



};



void test_k(char snn[])
{
    char x1;
    char x2;
    char x3;

    x1 = snn[0] ;
    x2 = snn[1] ;
    x3 = snn[2] ;

    cout << x1 << endl;
    cout << x2 << endl;
    cout << x3 << endl;


}

int main() {


    char xxx[3];
    xxx[0] = '0' ;
    xxx[1] = '1' ;
    xxx[2] = '2' ;

    test_k(xxx);




        Koral k1;
        Koral k2;

        k1.id_sznura[0] = '1';
        k1.id_sznura[1] = '2';
        k1.id_sznura[2] = '3';
        k2.id_sznura[0] = '0';
        k2.id_sznura[1] = '1';
        k2.id_sznura[2] = '2';
        cout << (k1.id_sznura > k2.id_sznura) << endl;

        cout << "Hello, World!" << endl;


        return 0;
}
