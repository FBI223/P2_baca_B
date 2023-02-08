#include <iostream>

using namespace std;


struct Koral
{
    short id_korala = 0;
    //char id_sznura[3] ;

    char id_sz_0;
    char id_sz_1;
    char id_sz_2;

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



    void czy_mniejszt_id_sznura___lewa_mniejsza_od_prawej(Koral* k1, Koral* k2  )
    {



    }

    void add_wiazanie_do_korala( Koral* k1 )
    {

        temp = koniec ;

        if ( poczatek == nullptr )
        {


            poczatek = new Koral;
            koniec = poczatek;
            temp = poczatek;

            poczatek->id_sz_0 = k1->id_sz_0 ;
            poczatek->id_sz_1 = k1->id_sz_1 ;
            poczatek->id_sz_2 = k1->id_sz_2 ;

            poczatek->id_korala = k1->id_korala;
            poczatek->next = nullptr;


        } else
        {

//            while ( (k1->id_sz_0 < temp->id_sz_0 )  )
//            {
//                temp = temp->prev;
//
//            }

            while ( ( k1->id_sz_0 == temp->id_sz_0 ) && ( k1->id_sz_1 < temp->id_sz_1 ) )
            {
                temp = temp->prev;

            }
            while ( ( k1->id_sz_0 == temp->id_sz_0 ) && ( k1->id_sz_1 == temp->id_sz_1 ) && ( k1->id_sz_2 < temp->id_sz_2 )  )
            {
                temp = temp->prev;
            }

            if ( temp == nullptr )
            {


                poczatek->prev = new Koral;
                poczatek->prev->id_sz_0 = k1->id_sz_0 ;
                poczatek->prev->id_sz_1 = k1->id_sz_1 ;
                poczatek->prev->id_sz_2 = k1->id_sz_2 ;
                poczatek->prev->id_korala = k1->id_korala ;
                poczatek->prev->next = poczatek;
                poczatek = poczatek->prev ;



            } else if ( ( k1->id_sz_0 > temp->id_sz_0  ) || ( (k1->id_sz_0 == temp->id_sz_0) && (k1->id_sz_1 > temp->id_sz_1 ) || ( (k1->id_sz_0 == temp->id_sz_0) &&  (k1->id_sz_1 == temp->id_sz_1) && (k1->id_sz_2 > temp->id_sz_2 ) ) ) )
            {

                temp = koniec;

                koniec->next = new Koral;
                koniec = koniec->next ;
                koniec->id_sz_0 = k1->id_sz_0 ;
                koniec->id_sz_1 = k1->id_sz_1 ;
                koniec->id_sz_2 = k1->id_sz_2 ;
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
                    poczatek->prev->id_sz_0  = k1->id_sz_0  ;
                    poczatek->prev->id_sz_1  = k1->id_sz_1  ;
                    poczatek->prev->id_sz_2  = k1->id_sz_2  ;
                    poczatek->prev->id_korala = k1->id_korala ;
                    poczatek->prev->next = poczatek;
                    poczatek = poczatek->prev ;

                } else if ( temp->id_korala < k1->id_korala  )
                {


                    temp = koniec;

                    koniec->next = new Koral;
                    koniec = koniec->next ;
                    koniec->id_sz_0  = k1->id_sz_0  ;
                    koniec->id_sz_1  = k1->id_sz_1  ;
                    koniec->id_sz_2  = k1->id_sz_2  ;
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

                    temp->id_sz_0  = k1->id_sz_0  ;
                    temp->id_sz_1  = k1->id_sz_1  ;
                    temp->id_sz_2  = k1->id_sz_2  ;
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

    char id_sz_0 ;
    char id_sz_1 ;
    char id_sz_2 ;

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

    void add_sznur( char y0, char y1, char y2 )
    {

        if ( first == nullptr )
        {
            first = new Sznur;

            first->id_sz_0 = y0 ;
            first->id_sz_1 = y1 ;
            first->id_sz_2 = y2 ;

            last = first;


        } else
        {


            temp = last ;
            while ( ( y0 < temp->id_sz_0  ) || ( ( y0 == temp->id_sz_0) && ( y1 < temp->id_sz_1 ) || ( ( y0 == temp->id_sz_0) &&  ( y1 == temp->id_sz_1) && ( y2 < temp->id_sz_2 ) )  ) )
            {
                temp = temp->prev;
            }

            if ( temp == nullptr )
            {
                first->prev = new Sznur;
                first->prev->next = first;
                first = first->prev ;

                first->id_sz_0 = y0 ;
                first->id_sz_1 = y1 ;
                first->id_sz_2 = y2 ;

            } else if ( ( ( y0 > temp->id_sz_0  ) || ( ( y0 == temp->id_sz_0) && ( y1 > temp->id_sz_1 ) || ( ( y0 == temp->id_sz_0) &&  ( y1 == temp->id_sz_1) && ( y2 > temp->id_sz_2 ) )  ) )  && (temp == last) )
            {
                temp->next = new Sznur;
                temp->next->prev = temp ;
                last = temp->next ;

                last->id_sz_0 = y0 ;
                last->id_sz_1 = y1 ;
                last->id_sz_2 = y2 ;

            } else
            {

                temp_2 = temp->next ;
                temp->next = new Sznur;
                temp->next->prev = temp;

                temp_2->prev = temp->next;
                temp_2->prev->next =  temp_2 ;

                temp = temp->next ;

                temp->id_sz_0 = y0 ;
                temp->id_sz_1 = y1 ;
                temp->id_sz_2 = y2 ;

            }


        }

    }



    void add_koral( char id_sznura_0, char id_sznura_1, char id_sznura_2 , int id_korala )
    {
        temp = last;
        while ( (temp->id_sz_0 != id_sznura_0) && (temp->id_sz_1 != id_sznura_1) && (temp->id_sz_2 != id_sznura_2 ) )
        {
            temp = temp->prev ;
        }

        temp->temp = temp->last;
        while ( temp->temp->Koral->id_korala > id_korala )
        {
            temp->temp = temp->temp->prev;
        }

        if ( temp->temp == nullptr )
        {
            temp->first->prev = new Koral_z_wiazaniami;
            temp->first->prev->next = temp->first ;

            temp->first = temp->first->prev;
            temp->first->Koral->id_korala = id_korala ;
        } else if ( (temp->temp == temp->last) && ( temp->temp->Koral->id_korala < id_korala ) )\
        {
            temp->temp->next = new Koral_z_wiazaniami;
            temp->temp->next->prev = temp->last ;

            temp->last = temp->last->next;
            temp->temp = temp->last->next;

            temp->temp->Koral->id_korala = id_korala ;
            // uzupelnij id sznura w kazdym koraliku !!!!
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



        cout << "Hello, World!" << endl;


        return 0;
}
