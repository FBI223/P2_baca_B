#include <iostream>

using namespace std;


// w add wiazanie albo

// obczaj sznury tak jak akorale

// add koral i add sznur popraw


struct Koral
{
    short id_korala = 0;
    //char id_sznura[3] ;

    char id_sz_0;
    char id_sz_1;
    char id_sz_2;


    Koral* prev = nullptr;
    Koral* next = nullptr;



    Koral* wsk_na_wiazany_element= nullptr;

    int ile_wiazan;
    Koral* pierwsze_wiazanie= nullptr;
    Koral* ostatnie_wiazanie= nullptr;
    Koral* temp_wiazanie= nullptr;


    void add_wiazanie_do_korala(Koral* ko )
    {


        Koral* temp_wiazanie_2= nullptr;

        ile_wiazan += 1 ;

        cout << "flaga 1 " << endl;

        if ( pierwsze_wiazanie == nullptr )
        {

            cout <<"----------------- dodawanie wiazania ----------------" << endl;

            pierwsze_wiazanie = new Koral;
            ostatnie_wiazanie = pierwsze_wiazanie;
            cout << "xd 1 " << endl;
            pierwsze_wiazanie->wsk_na_wiazany_element = ko;
            cout << "xd 2 " << endl;


            //cout <<ko->id_korala<< "   " <<id_sz_0 << id_sz_1 << id_sz_2<< id_korala << endl;
            pierwsze_wiazanie->id_sz_0 = ko->id_sz_0;
            pierwsze_wiazanie->id_sz_1 = ko->id_sz_1;
            pierwsze_wiazanie->id_sz_2 = ko->id_sz_2;
            pierwsze_wiazanie->id_korala = ko->id_korala;
            cout << "xd 3 " << endl;
            temp_wiazanie = pierwsze_wiazanie;

            cout << "xd 4 " << endl;
            pierwsze_wiazanie->next = nullptr;
            pierwsze_wiazanie->prev = nullptr;

//            cout << pierwsze_wiazanie << endl;
//            cout << pierwsze_wiazanie->wsk_na_wiazany_element << endl;
//            cout << ko << endl;
//            cout << pierwsze_wiazanie->wsk_na_wiazany_element->id_korala << endl;
//            cout << ko->id_korala << endl;


            cout << "flaga 2 " << endl;

        } else
        {

            temp_wiazanie= ostatnie_wiazanie;

            while ( ( temp_wiazanie !=nullptr ) && ((temp_wiazanie->id_sz_0 > ko->id_sz_0 ) || ( ( temp_wiazanie->id_sz_0 == ko->id_sz_0 ) && ( temp_wiazanie->id_sz_1 > ko->id_sz_1 ) ) || ( ( temp_wiazanie->id_sz_0 == ko->id_sz_0  ) && ( temp_wiazanie->id_sz_1 == ko->id_sz_1  ) && (  temp_wiazanie->id_sz_2 > ko->id_sz_2 ) ))  )
            {
                temp_wiazanie = temp_wiazanie->prev;

            }


            if ( temp_wiazanie != nullptr )
            {

                while ( (temp_wiazanie != nullptr) && (temp_wiazanie->id_korala > ko->id_korala) && (temp_wiazanie->id_sz_0 == ko->id_sz_0 ) && (temp_wiazanie->id_sz_1 == ko->id_sz_1 ) && (temp_wiazanie->id_sz_2 == ko->id_sz_2 ) )
                {
                    temp_wiazanie = temp_wiazanie->prev ;
                }

            }


            if ( temp_wiazanie == nullptr )
            {

                pierwsze_wiazanie->prev = new Koral;
                pierwsze_wiazanie->prev->next = pierwsze_wiazanie;

                pierwsze_wiazanie->prev->wsk_na_wiazany_element = ko;

                pierwsze_wiazanie = pierwsze_wiazanie->prev;

                pierwsze_wiazanie->id_sz_0 = ko->id_sz_0;
                pierwsze_wiazanie->id_sz_1 = ko->id_sz_1;
                pierwsze_wiazanie->id_sz_2 = ko->id_sz_2;
                pierwsze_wiazanie->id_korala = ko->id_korala;
                temp_wiazanie = pierwsze_wiazanie;

                pierwsze_wiazanie->prev = nullptr;

            } else if ( temp_wiazanie == ostatnie_wiazanie )
            {
                ostatnie_wiazanie->next = new Koral;
                ostatnie_wiazanie->next->prev = ostatnie_wiazanie;

                ostatnie_wiazanie->next->id_sz_0 = ko->id_sz_0;
                ostatnie_wiazanie->next->id_sz_1 = ko->id_sz_1;
                ostatnie_wiazanie->next->id_sz_2 = ko->id_sz_2;
                ostatnie_wiazanie->next->id_korala = ko->id_korala;
                ostatnie_wiazanie->next->wsk_na_wiazany_element = ko;

                ostatnie_wiazanie = ostatnie_wiazanie->next;
                ostatnie_wiazanie->next = nullptr;


            } else
            {

                temp_wiazanie_2 = temp_wiazanie->next;
                temp_wiazanie->next = new Koral;
                temp_wiazanie->next->prev = temp_wiazanie;
                temp_wiazanie_2->prev = temp_wiazanie->next;
                temp_wiazanie->next->next = temp_wiazanie_2;

                temp_wiazanie = temp_wiazanie->next;

                temp_wiazanie->id_sz_0 = ko->id_sz_0;
                temp_wiazanie->id_sz_1 = ko->id_sz_1;
                temp_wiazanie->id_sz_2 = ko->id_sz_2;

                temp_wiazanie->id_korala = ko->id_korala;

                temp_wiazanie->wsk_na_wiazany_element = ko;



            }





        }

//        cout <<"------------------ pow pow ---------------" << endl;
//
//        cout << pierwsze_wiazanie << endl;
//        cout << pierwsze_wiazanie->wsk_na_wiazany_element << endl;
//        cout << ko << endl;
//        cout << pierwsze_wiazanie->wsk_na_wiazany_element->id_korala << endl;
//        cout << ko->id_korala << endl;
//
//
//        cout << pierwsze_wiazanie << endl;
//
//        cout <<"---------------------------------" << endl;


    }


    void delete_wiazanie( int id_korala, char id_sz_0, char id_sz_1, char id_sz_2 )
    {

        Koral* temp_wiazanie_2= nullptr;

        Koral* usuwany_koral_dowiazany;


        temp_wiazanie = ostatnie_wiazanie ;

        cout << temp_wiazanie->id_korala<< "  " << temp_wiazanie->id_sz_0<<temp_wiazanie->id_sz_1<<temp_wiazanie->id_sz_2 << endl;

        while  (( temp_wiazanie->id_sz_0 != id_sz_0 ) && ( temp_wiazanie->id_sz_1 != id_sz_1) && (temp_wiazanie->id_sz_2 != id_sz_2)  )
        {
            temp_wiazanie = temp_wiazanie->prev ;
        }

        while ( temp_wiazanie->id_korala != id_korala )
        {
            temp_wiazanie = temp_wiazanie->prev ;
        }
        usuwany_koral_dowiazany = temp_wiazanie->wsk_na_wiazany_element ;


        if ( (temp_wiazanie->prev == nullptr) && ( temp_wiazanie->next == nullptr ) )
        {
            delete temp_wiazanie;
            temp_wiazanie = nullptr ;
            pierwsze_wiazanie = nullptr;
            ostatnie_wiazanie = nullptr;

        } else
        {




            if ( temp_wiazanie->prev == nullptr )
            {
                temp_wiazanie_2 = temp_wiazanie;
                pierwsze_wiazanie = temp_wiazanie->next;
                pierwsze_wiazanie->prev = nullptr;

                delete temp_wiazanie_2;
                cout << "tso 2" << endl;
            } else if( temp_wiazanie->next == nullptr )
            {

                temp_wiazanie_2 = temp_wiazanie;
                ostatnie_wiazanie = temp_wiazanie->prev ;
                ostatnie_wiazanie->next = nullptr;

                delete temp_wiazanie_2;
            } else
            {


                temp_wiazanie->prev->next = temp_wiazanie->next;
                temp_wiazanie->next->prev = temp_wiazanie->prev;

                delete temp_wiazanie;

            }


        }


    }



};



struct Sznur
{

    Sznur* next= nullptr;
    Sznur* prev= nullptr;

    char id_sz_0 ;
    char id_sz_1 ;
    char id_sz_2 ;

    int ile_korali = 0;

    Koral* first= nullptr ;
    Koral* last= nullptr;
    Koral* temp= nullptr;






};


struct Struktura
{
    int ile_sznurow = 0;

    Sznur* first = nullptr ;
    Sznur* last= nullptr ;
    Sznur* temp = nullptr;
    Sznur* temp_2= nullptr ;



    void add_sznur( char y0, char y1, char y2 )
    {

        if ( first == nullptr )
        {
            first = new Sznur;

            first->id_sz_0 = y0 ;
            first->id_sz_1 = y1 ;
            first->id_sz_2 = y2 ;

            last = first;


            first->prev = nullptr ;
            first->next = nullptr ;

            temp = first;



        } else
        {


            temp = last ;
            while ( ( temp != nullptr ) && (( y0 < temp->id_sz_0  ) ||  (( y0 == temp->id_sz_0) && ( y1 < temp->id_sz_1 )) || ( ( y0 == temp->id_sz_0) &&  ( y1 == temp->id_sz_1) && ( y2 < temp->id_sz_2 ) )  )  )
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

                first->prev = nullptr;

                temp = first;


            } else if (  (temp == last)  &&  ( ( y0 > temp->id_sz_0  ) ||  (( y0 == temp->id_sz_0) && ( y1 > temp->id_sz_1 )) || ( ( y0 == temp->id_sz_0) &&  ( y1 == temp->id_sz_1) && ( y2 > temp->id_sz_2 ) )   )   )
            {

                temp->next = new Sznur;
                temp->next->prev = temp ;
                last = temp->next ;

                last->id_sz_0 = y0 ;
                last->id_sz_1 = y1 ;
                last->id_sz_2 = y2 ;

                last->next = nullptr;

                temp = last;

            } else
            {

                temp->next->prev = new Sznur;
                temp->next->prev->next = temp->next;

                temp->next = temp->next->prev;
                temp->next->prev = temp;

                temp = temp->next;

                temp->id_sz_0 = y0 ;
                temp->id_sz_1 = y1 ;
                temp->id_sz_2 = y2 ;


            }


        }


    }



    void add_koral( char id_sznura_0, char id_sznura_1, char id_sznura_2 , int id_korala )
    {




        temp = last;


        while ( ( temp != nullptr ) && ((temp->id_sz_0 != id_sznura_0) && (temp->id_sz_1 != id_sznura_1) && (temp->id_sz_2 != id_sznura_2 ))   )
        {
            temp = temp->prev ;
        }


        temp->temp = temp->last;


        cout << temp->temp << endl;


        while ( ( temp->temp != nullptr ) && (temp->temp->id_korala > id_korala)  )
        {
            temp->temp = temp->temp->prev;
            cout << temp->temp << endl;
        }

        if ( temp->temp == nullptr )
        {


            if ( temp->first == nullptr )
            {
                temp->first = new Koral;
                temp->first->id_sz_0 = id_sznura_0 ;
                temp->first->id_sz_1 = id_sznura_1 ;
                temp->first->id_sz_2 = id_sznura_2;

                temp->first->id_korala = id_korala;

                temp->first->prev = nullptr;
                temp->first->next = nullptr;

                temp->last = temp->first;

                temp->last->next = nullptr;
                temp->last->prev = nullptr;




            } else
            {


                temp->first->prev = new Koral ;
                temp->first->prev->id_sz_0 = temp->id_sz_0;
                temp->first->prev->id_sz_1 = temp->id_sz_1;
                temp->first->prev->id_sz_2 = temp->id_sz_2;

                temp->first->prev->next = temp->first ;

                temp->first = temp->first->prev;
                temp->first->id_korala = id_korala ;
                temp->first->prev = nullptr ;


            }


        } else if ( (temp->temp == temp->last) && ( temp->temp->id_korala < id_korala ) )
        {
            temp->temp->next = new Koral ;
            temp->temp->next->id_sz_0 = temp->id_sz_0;
            temp->temp->next->id_sz_1 = temp->id_sz_1;
            temp->temp->next->id_sz_2 = temp->id_sz_2;

            temp->temp->next->id_korala= id_korala;
            temp->temp->next->prev = temp->last ;

            temp->last = temp->last->next;
            temp->temp = temp->last;

            temp->last->next = nullptr;




            // uzupelnij id sznura w kazdym koraliku !!!!
        } else if  ( temp->temp->next != nullptr )
        {




            temp->temp->next->prev = new Koral;
            temp->temp->next->prev->next = temp->temp->next;

            temp->temp->next = temp->temp->next->prev;
            temp->temp->next->prev = temp->temp;

            temp->temp = temp->temp->next;

            temp->temp->id_sz_0 = temp->id_sz_0 ;
            temp->temp->id_sz_1 = temp->id_sz_1 ;
            temp->temp->id_sz_2 = temp->id_sz_2 ;

            temp->temp->id_korala = id_korala;


        }



    }




    Sznur* add_koral_2( char id_sznura_0, char id_sznura_1, char id_sznura_2 , int id_korala )
    {
        temp = last;
        while ( ( temp !=nullptr ) && ((temp->id_sz_0 != id_sznura_0) && (temp->id_sz_1 != id_sznura_1) && (temp->id_sz_2 != id_sznura_2 )) )
        {
            temp = temp->prev ;
        }

        temp->temp = temp->last;

        while ( ( temp->temp != nullptr ) && (temp->temp->id_korala > id_korala)  )
        {
            temp->temp = temp->temp->prev;
        }

        if ( temp->temp == nullptr )
        {

            if ( temp->first == nullptr )
            {

                temp->first = new Koral;
                temp->first->id_sz_0 = id_sznura_0 ;
                temp->first->id_sz_1 = id_sznura_1 ;
                temp->first->id_sz_2 = id_sznura_2;

                temp->first->id_korala = id_korala;

                temp->first->prev = nullptr;
                temp->first->next = nullptr;

                temp->last = temp->first;

                temp->last->next = nullptr;
                temp->last->prev = nullptr;


            } else
            {

                temp->first->prev = new Koral ;
                temp->first->prev->id_sz_0 = temp->id_sz_0;
                temp->first->prev->id_sz_1 = temp->id_sz_1;
                temp->first->prev->id_sz_2 = temp->id_sz_2;

                temp->first->prev->next = temp->first ;

                temp->first = temp->first->prev;
                temp->first->id_korala = id_korala ;
                temp->first->prev = nullptr ;

            }


        } else if ( (temp->temp == temp->last) && ( temp->temp->id_korala < id_korala ) )
        {
            temp->temp->next = new Koral ;
            temp->temp->next->id_sz_0 = temp->id_sz_0;
            temp->temp->next->id_sz_1 = temp->id_sz_1;
            temp->temp->next->id_sz_2 = temp->id_sz_2;

            temp->temp->next->id_korala= id_korala;
            temp->temp->next->prev = temp->last ;

            temp->last = temp->last->next;
            temp->temp = temp->last;

            temp->last->next = nullptr;
            // uzupelnij id sznura w kazdym koraliku !!!!
        } else
        {


            temp->temp->next->prev = new Koral;
            temp->temp->next->prev->next = temp->temp->next;

            temp->temp->next = temp->temp->next->prev;
            temp->temp->next->prev = temp->temp;

            temp->temp = temp->temp->next;

            temp->temp->id_sz_0 = temp->id_sz_0 ;
            temp->temp->id_sz_1 = temp->id_sz_1 ;
            temp->temp->id_sz_2 = temp->id_sz_2 ;

            temp->temp->id_korala = id_korala;



        }

        return temp;

    }


    void dodaj_wiazanie_z_a_do_b_i_z_b_do_a(int id_korala_z, int id_korala_do, char id_sz_z_0, char id_sz_z_1, char id_sz_z_2, char id_sz_do_0, char id_sz_do_1, char id_sz_do_2 )
    {
    Sznur* temp_sznur = last ;

    Koral* koral_z = nullptr;
    Koral* koral_do = nullptr;

    cout << " A " << endl;

    while( (temp_sznur->id_sz_0 != id_sz_z_0) && (temp_sznur->id_sz_1 != id_sz_z_1 ) && ( temp_sznur->id_sz_2 != id_sz_z_2 ) )
    {
        temp_sznur = temp_sznur->prev ;
    }

        cout << " B " << endl;

    koral_z = temp_sznur->last;
    while ( koral_z->id_korala != id_korala_z )
    {
        koral_z = koral_z->prev ;
    }


        cout << " C " << endl;

    if ( (id_sz_z_0=id_sz_do_0)&&(id_sz_z_1==id_sz_do_1)&&(id_sz_z_2==id_sz_do_2) )
    {

        cout << " D " << endl;

        koral_do = temp_sznur->last;

        cout << " E " << endl;

        while ( koral_do->id_korala != id_korala_do )
        {
            koral_do = koral_do->prev;
        }

        cout << " F " << endl;


        //cout << "id korala z : " <<temp_sznur_z->temp->id_sz_0 <<temp->id_sz_1 <<temp->id_sz_2 << temp_sznur_z->temp->id_korala <<endl;
        //cout << "id korala do : " << temp_sznur_do->temp->id_sz_0<<temp_sznur_do->temp->id_sz_1<<temp_sznur_do->temp->id_sz_2 <<temp_sznur_do->temp->id_korala <<endl;


        cout << " G " << endl;

    }else
    {

        cout << " H " << endl;

        temp_sznur = last;
        while( (temp_sznur->id_sz_0 != id_sz_do_0) && (temp_sznur->id_sz_1 != id_sz_do_1 ) && ( temp_sznur->id_sz_2 != id_sz_do_2 ) )
        {
            temp_sznur = temp_sznur->prev ;
        }

        cout << " I " << endl;

        koral_do = temp_sznur->last;
        cout << " I2 " << endl;
        while ( koral_do->id_korala != id_korala_do )
        {
            cout << " I3 " << endl;
            koral_do = koral_do->prev ;
        }


        cout << " J " << endl;
        koral_do = temp_sznur->temp;

    }

        cout << " K " << endl;
    koral_z->add_wiazanie_do_korala( koral_do );

        cout << " L " << endl;

    if ( !(  (id_sz_z_0=id_sz_do_0)&&(id_sz_z_1==id_sz_do_1)&&(id_sz_z_2==id_sz_do_2)&&(id_korala_z == id_korala_do) ) )
    {
        cout << " M " << endl;
        koral_do->add_wiazanie_do_korala(koral_z);
    }


        cout << " N " << endl;

    }

    void usun_wiazanie_z_a_do_b(int id_korala_z, int id_korala_do, char id_sz_z_0, char id_sz_z_1, char id_sz_z_2, char id_sz_do_0, char id_sz_do_1, char id_sz_do_2 )
    {

        Koral* koral_main= nullptr;

        Sznur* temp_sznur_z = last ;

        Koral* usuwany_koral_dowiazanie;


        while( (temp_sznur_z->id_sz_0 != id_sz_z_0) && (temp_sznur_z->id_sz_1 != id_sz_z_1 ) && ( temp_sznur_z->id_sz_2 != id_sz_z_2 ) )
        {
            temp_sznur_z = temp_sznur_z->prev ;
        }

        temp_sznur_z->temp = temp_sznur_z->last;
        while ( temp_sznur_z->temp->id_korala != id_korala_z )
        {
            temp_sznur_z->temp = temp_sznur_z->temp->prev ;
        }

        koral_main = temp_sznur_z->temp;


        koral_main->delete_wiazanie( id_korala_do,id_sz_do_0,id_sz_do_1,id_sz_do_2 ) ;
        //usuwany_koral_dowiazanie->delete_wiazanie(id_korala_z,id_sz_z_0,id_sz_z_1,id_sz_z_2) ;


    }


    void usun_korala_z_jego_powiazaniami( char id_sz_0, char id_sz_1, char id_sz_2, int id_korala )
    {


        cout << "-------------MARYSIA------------" << endl;
        temp = last;

        Koral* koral_usuwany = nullptr;

        Koral* temppp;


        while ( (temp->id_sz_0 != id_sz_0) && (temp->id_sz_1 != id_sz_1 ) && ( temp->id_sz_2 != id_sz_2 ) )
        {
            temp = temp->prev ;
        }


        temp->temp = temp->last ;
        while (  temp->temp->id_korala != id_korala )
        {
            temp->temp = temp->temp->prev;
        }
        Koral* koral_przenoszony_stara_lokalizacja = temp->temp;

        koral_usuwany = temp->temp ;


        Koral* temp_usuwanie = temp->temp->ostatnie_wiazanie;


        while ( temp_usuwanie != nullptr )
        {


//            cout << temp_usuwanie->wsk_na_wiazany_element << endl;
//            cout << koral_usuwany << endl;
//            cout << temp_usuwanie->wsk_na_wiazany_element->id_korala << endl;
//            cout << koral_usuwany->id_korala << endl;



            if ( temp_usuwanie->wsk_na_wiazany_element != koral_usuwany )
            {
                temp_usuwanie->wsk_na_wiazany_element->delete_wiazanie(id_korala,id_sz_0,id_sz_1,id_sz_2) ;
                temppp = temp_usuwanie;
                temp_usuwanie = temp_usuwanie->prev;
            } else
            {
                temppp = temp_usuwanie;
                temp_usuwanie = temp_usuwanie->prev;
            }

        }

        Sznur* temp_wsk_sznur_stary_koral = temp;



        if ( ( koral_przenoszony_stara_lokalizacja->next == nullptr ) && ( koral_przenoszony_stara_lokalizacja->prev == nullptr )  )
        {
            temp_wsk_sznur_stary_koral->first = nullptr;
            temp_wsk_sznur_stary_koral->last = nullptr;
            delete koral_przenoszony_stara_lokalizacja;


        } else if ( koral_przenoszony_stara_lokalizacja->next == nullptr  )
        {
            temp_wsk_sznur_stary_koral->last = temp_wsk_sznur_stary_koral->last->prev;
            temp_wsk_sznur_stary_koral->last->next = nullptr;
            delete koral_przenoszony_stara_lokalizacja;

        } else if ( koral_przenoszony_stara_lokalizacja->prev == nullptr )
        {

            temp_wsk_sznur_stary_koral->first = temp_wsk_sznur_stary_koral->first->next;
            temp_wsk_sznur_stary_koral->first->prev = nullptr;
            delete koral_przenoszony_stara_lokalizacja;
        } else
        {
            koral_przenoszony_stara_lokalizacja->prev->next = koral_przenoszony_stara_lokalizacja->next ;
            koral_przenoszony_stara_lokalizacja->next->prev = koral_przenoszony_stara_lokalizacja->prev ;
            delete koral_przenoszony_stara_lokalizacja;

        }




    }


    void usun_korala_z_jego_powiazaniami_2( Koral* usuwany_koral )
    {

        Koral* temppp;
        Koral* temp_usuwanie = usuwany_koral->ostatnie_wiazanie ;

        temp = last;

        Koral* koral_usuwany = nullptr;


        while ( (temp->id_sz_0 != usuwany_koral->id_sz_0) && (temp->id_sz_1 != usuwany_koral->id_sz_1 ) && ( temp->id_sz_2 != usuwany_koral->id_sz_2 ) )
        {
            temp = temp->prev ;
        }

        temp->temp = temp->last ;
        while (  temp->temp->id_korala != usuwany_koral->id_korala )
        {
            temp->temp = temp->temp->prev;
        }
        koral_usuwany = temp->temp ;


        temp_usuwanie = temp->temp->ostatnie_wiazanie;

        while ( temp_usuwanie != nullptr )
        {


//            cout << temp_usuwanie->wsk_na_wiazany_element << endl;
//            cout << koral_usuwany << endl;
//            cout << temp_usuwanie->wsk_na_wiazany_element->id_korala << endl;
//            cout << koral_usuwany->id_korala << endl;
//


            if ( temp_usuwanie->wsk_na_wiazany_element != koral_usuwany )
            {
                temp_usuwanie->wsk_na_wiazany_element->delete_wiazanie(usuwany_koral->id_korala,usuwany_koral->id_sz_0,usuwany_koral->id_sz_1,usuwany_koral->id_sz_2) ;
                temppp = temp_usuwanie;
                temp_usuwanie = temp_usuwanie->prev;
            } else
            {
                temppp = temp_usuwanie;
                temp_usuwanie = temp_usuwanie->prev;
            }

            delete temppp ; // czy dobry sposob na delete ?

        }

        temppp = temp->temp;

        if ( temp->temp->prev == nullptr )
        {
            temp->first = temp->first->next;
            temp->first->prev = nullptr;
        } else if ( temp->temp->next == nullptr )
        {

            temp->last = temp->last->prev;
            temp->last->next = nullptr;

        } else
        {

            temp->temp->prev->next = temp->temp->next;
            temp->temp->next->prev = temp->temp->prev;

        }

        delete temppp ;




    }



    void przenosiny_korala(int id_korala_przenoszonego, char id_sz_0_przenoszonego, char id_sz_1_przenoszonego,char id_sz_2_przenoszonego, char id_sz_0_docelowego,char id_sz_1_docelowego,char id_sz_2_docelowego )
    {


        cout << "-------------------------ZACZYNAMY PRZENOSINY----------------------------" << endl;

        Sznur* temp_wsk_sznur = last ;
        Sznur* temp_wsk_sznur_stary_koral = last ;
        Sznur* temp_wsk_sznur_nowy_koral = last ;


        cout << "FLAGA 00 " << endl;

        Koral* koral_przenoszony_stara_lokalizacja = temp_wsk_sznur->last;
        cout << "FLAGA 01 " << endl;
        Koral* temp_wiazanie ;
        cout << "FLAGA 02 " << endl;
        Koral* temp_wiazanie_usuwane;
        cout << "FLAGA 03 " << endl;
        Koral* koral_przenoszony_nowa_lokalizacja = temp_wsk_sznur->last;


        cout << "FLAGA 1 " << endl;

        while ( (temp_wsk_sznur->id_sz_0 != id_sz_0_przenoszonego ) && ( temp_wsk_sznur->id_sz_1 != id_sz_1_przenoszonego ) && (temp_wsk_sznur->id_sz_0 != id_sz_2_przenoszonego ))
        {
            temp_wsk_sznur = temp_wsk_sznur->prev ;
        }
        cout << "FLAGA 2 " << endl;
        temp_wsk_sznur_stary_koral = temp_wsk_sznur;
        koral_przenoszony_stara_lokalizacja = temp_wsk_sznur->last;
        cout << "FLAGA 3 " << endl;
        while ( koral_przenoszony_stara_lokalizacja->id_korala != id_korala_przenoszonego )
        {
            koral_przenoszony_stara_lokalizacja = koral_przenoszony_stara_lokalizacja->prev ;
        }

        cout << "FLAGA 4 " << endl;


        temp_wsk_sznur = last;
        while ( (temp_wsk_sznur->id_sz_0 != id_sz_0_docelowego ) && ( temp_wsk_sznur->id_sz_1 != id_sz_1_docelowego ) && (temp_wsk_sznur->id_sz_0 != id_sz_2_docelowego ))
        {
            temp_wsk_sznur = temp_wsk_sznur->prev ;
        }
        temp_wsk_sznur_nowy_koral = temp_wsk_sznur;

        cout << "FLAGA 5 " << endl;

        add_koral( id_sz_0_docelowego, id_sz_1_docelowego, id_sz_2_docelowego, id_korala_przenoszonego ) ;

        cout << "FLAGA 6 " << endl;

        koral_przenoszony_nowa_lokalizacja = temp_wsk_sznur->last;
        cout << "FLAGA 7 " << endl;

        while ( koral_przenoszony_nowa_lokalizacja->id_korala != id_korala_przenoszonego )
        {
            koral_przenoszony_nowa_lokalizacja = koral_przenoszony_nowa_lokalizacja->prev ;
        }

        cout << "FLAGA 8 " << endl;

        temp_wiazanie = koral_przenoszony_stara_lokalizacja->ostatnie_wiazanie ;
        cout << "FLAGA 9 " << endl;
        while ( temp_wiazanie != nullptr )
        {

            cout << "FLAGA 10 " << endl;

            temp_wiazanie_usuwane = temp_wiazanie;
            if ( temp_wiazanie->wsk_na_wiazany_element != koral_przenoszony_stara_lokalizacja )
            {

                cout << "FLAGA 11 " << endl;
                dodaj_wiazanie_z_a_do_b_i_z_b_do_a( koral_przenoszony_nowa_lokalizacja->id_korala, temp_wiazanie->id_korala , koral_przenoszony_nowa_lokalizacja->id_sz_0,koral_przenoszony_nowa_lokalizacja->id_sz_1 , koral_przenoszony_nowa_lokalizacja->id_sz_2 , temp_wiazanie->id_sz_0, temp_wiazanie->id_sz_1,temp_wiazanie->id_sz_2 ) ;
                cout << "FLAGA 12 " << endl;
                koral_przenoszony_stara_lokalizacja->delete_wiazanie(temp_wiazanie->id_korala, temp_wiazanie->id_sz_0,temp_wiazanie->id_sz_1,temp_wiazanie->id_sz_2);
                cout << "FLAGA 13 " << temp_wiazanie->id_korala << "  "<< temp_wiazanie->id_sz_0 << temp_wiazanie->id_sz_1<<temp_wiazanie->id_sz_2 << endl;
                cout << "FLAGA 13 " << koral_przenoszony_stara_lokalizacja->id_korala << "  "<< koral_przenoszony_stara_lokalizacja->id_sz_0 << koral_przenoszony_stara_lokalizacja->id_sz_1<<koral_przenoszony_stara_lokalizacja->id_sz_2 << endl;
            } else
            {
                cout << "FLAGA 14 " << endl;
                dodaj_wiazanie_z_a_do_b_i_z_b_do_a( koral_przenoszony_nowa_lokalizacja->id_korala,koral_przenoszony_nowa_lokalizacja->id_korala,koral_przenoszony_nowa_lokalizacja->id_sz_0,koral_przenoszony_nowa_lokalizacja->id_sz_1 , koral_przenoszony_nowa_lokalizacja->id_sz_2,koral_przenoszony_nowa_lokalizacja->id_sz_0,koral_przenoszony_nowa_lokalizacja->id_sz_1 , koral_przenoszony_nowa_lokalizacja->id_sz_2 ) ;
                cout << "FLAGA 15 " << endl;
                koral_przenoszony_stara_lokalizacja->delete_wiazanie(koral_przenoszony_stara_lokalizacja->id_korala, koral_przenoszony_stara_lokalizacja->id_sz_0 ,koral_przenoszony_stara_lokalizacja->id_sz_1 ,koral_przenoszony_stara_lokalizacja->id_sz_2 ) ;
                cout << "FLAGA 15 " << endl;
            }

            cout << "FLAGA 16 " << endl;
            temp_wiazanie = temp_wiazanie->prev;
            cout << "FLAGA 17 " << endl;
        }
        cout << "FLAGA 18 " << endl;


        if ( (koral_przenoszony_stara_lokalizacja->next == nullptr ) && ( koral_przenoszony_stara_lokalizacja->prev == nullptr )  )
        {
             temp_wsk_sznur_stary_koral->first = nullptr;
             temp_wsk_sznur->last = nullptr;
             delete koral_przenoszony_stara_lokalizacja;


        } else if ( koral_przenoszony_stara_lokalizacja->next == nullptr  )
        {
            temp_wsk_sznur_stary_koral->last = temp_wsk_sznur_stary_koral->last->prev;
            temp_wsk_sznur_stary_koral->last->next = nullptr;
            delete koral_przenoszony_stara_lokalizacja;

        } else if ( koral_przenoszony_stara_lokalizacja->prev == nullptr )
        {

            temp_wsk_sznur_stary_koral->first = temp_wsk_sznur_stary_koral->first->next;
            temp_wsk_sznur_stary_koral->first->prev = nullptr;
            delete koral_przenoszony_stara_lokalizacja;
        } else
        {
            koral_przenoszony_stara_lokalizacja->prev->next = koral_przenoszony_stara_lokalizacja->next ;
            koral_przenoszony_stara_lokalizacja->next->prev = koral_przenoszony_stara_lokalizacja->prev ;
            delete koral_przenoszony_stara_lokalizacja;

        }


        //usun_korala_z_jego_powiazaniami( koral_przenoszony_stara_lokalizacja->id_sz_0, koral_przenoszony_stara_lokalizacja->id_sz_1, koral_przenoszony_stara_lokalizacja->id_sz_2,koral_przenoszony_stara_lokalizacja->id_korala ) ;



    }

    void usuniecie_sznura_z_koralami_i_ich_wiazaniami(char id_sz_0_us, char id_sz_1_us,char id_sz_2_us)
    {

        temp = last;

        Koral* koral_dojezdzany;


        cout<< "--------------------------------------------avi 1 "<< endl;
        while ( (temp->id_sz_0 != id_sz_0_us) && ( temp->id_sz_1 != id_sz_1_us  ) &&  ( temp->id_sz_2 != id_sz_2_us  ) )
        {
            temp = temp->prev;
        }

        cout<< "--------------------------------------------avi 2 "<< endl;

        temp->temp = temp->last;
        koral_dojezdzany = temp->temp;
//        cout << "poka" << endl;
//        cout << id_sz_0_us << id_sz_1_us << id_sz_2_us << endl;
//        cout << koral_dojezdzany->id_sz_0 <<koral_dojezdzany->id_sz_1 << koral_dojezdzany->id_sz_2 <<"  "<<koral_dojezdzany->id_korala <<endl;
//        cout << "poka" << endl;
        while ( koral_dojezdzany != nullptr )
        {
//            cout << "poka" << endl;
//            cout << id_sz_0_us << id_sz_1_us << id_sz_2_us << endl;
//            cout << koral_dojezdzany->id_sz_0 <<koral_dojezdzany->id_sz_1 << koral_dojezdzany->id_sz_2 <<"  "<<koral_dojezdzany->id_korala <<endl;
//            cout << "poka" << endl;
//            cout<< "--------------------------------------------avi 3 " <<endl;
            //usun_korala_z_jego_powiazaniami_2(koral_dojezdzany );
            usun_korala_z_jego_powiazaniami( koral_dojezdzany->id_sz_0,koral_dojezdzany->id_sz_1,koral_dojezdzany->id_sz_2,koral_dojezdzany->id_korala);
            temp->temp = temp->temp->prev;
            koral_dojezdzany = temp->temp;
//            cout << "poka2" << endl;
//            cout << id_sz_0_us << id_sz_1_us << id_sz_2_us << endl;
//            cout << koral_dojezdzany->id_sz_0 <<koral_dojezdzany->id_sz_1 << koral_dojezdzany->id_sz_2 <<"  "<<koral_dojezdzany->id_korala <<endl;
//            cout << "poka2" << endl;

            cout<< "--------------------------------------------avi 4 "<< endl;
        }


        cout<< "--------------------------------------------avi 5 " <<endl;

        temp_2 = temp;
        if ( temp->prev == nullptr )
        {
            first = first->next;
            first->prev = nullptr;

        } else if ( temp->next == nullptr )
        {
            last = last->prev;
            last->next = nullptr;

        } else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;

    }


    void pokaz_wszystko_P()
    {
        Koral* temp_wiazanie_pokaz;


        temp = first;
        while ( temp != nullptr )
        {


            cout << temp->id_sz_0<<temp->id_sz_1<<temp->id_sz_2<<endl;
            cout << " flaga 6.6 " << endl;
            temp->temp = temp->first;
            while ( temp->temp != nullptr )
            {
                cout << temp->temp << endl;
                cout << temp->temp->next << endl;

                temp_wiazanie_pokaz = temp->temp->pierwsze_wiazanie;

                if ( temp_wiazanie_pokaz == nullptr )
                {
                    cout << temp->temp->id_korala<<endl;
                } else
                {
                    cout << temp->temp->id_korala<<' ';

                    while ( temp_wiazanie_pokaz != nullptr )
                    {

                        //cout << " flaga 8 " << endl;
                        if ( temp_wiazanie_pokaz->next == nullptr )
                        {
                            cout << temp_wiazanie_pokaz->id_sz_0<<temp_wiazanie_pokaz->id_sz_1<<temp_wiazanie_pokaz->id_sz_2<< ' '<<temp_wiazanie_pokaz->id_korala<<endl;
                        }
                        else
                        {
                            cout << temp_wiazanie_pokaz->id_sz_0<<temp_wiazanie_pokaz->id_sz_1<<temp_wiazanie_pokaz->id_sz_2<< ' '<<temp_wiazanie_pokaz->id_korala<< ' ';
                        }


                        temp_wiazanie_pokaz = temp_wiazanie_pokaz->next;
                        //cout << "temp wiazanie pokaz " << temp_wiazanie_pokaz << endl;
                    }

                }


                temp->temp = temp->temp->next;

            }

            temp = temp->next ;
        }
    }






    void pokaz_wszystko_P_na_czysto()
    {
        Koral* temp_wiazanie_pokaz;


        temp = first;
        while ( temp != nullptr )
        {

            cout << temp->id_sz_0<<temp->id_sz_1<<temp->id_sz_2<<endl;
            temp->temp = temp->first;
            while ( temp->temp != nullptr )
            {

                temp_wiazanie_pokaz = temp->temp->pierwsze_wiazanie;

                if ( temp_wiazanie_pokaz == nullptr )
                {
                    cout << temp->temp->id_korala<<endl;
                } else
                {
                    cout << temp->temp->id_korala<<' ';

                    while ( temp_wiazanie_pokaz != nullptr )
                    {

                        if ( temp_wiazanie_pokaz->next == nullptr )
                        {
                            cout << temp_wiazanie_pokaz->id_sz_0<<temp_wiazanie_pokaz->id_sz_1<<temp_wiazanie_pokaz->id_sz_2<< ' '<<temp_wiazanie_pokaz->id_korala<<endl;
                        }
                        else
                        {
                            cout << temp_wiazanie_pokaz->id_sz_0<<temp_wiazanie_pokaz->id_sz_1<<temp_wiazanie_pokaz->id_sz_2<< ' '<<temp_wiazanie_pokaz->id_korala<< ' ';
                        }


                        temp_wiazanie_pokaz = temp_wiazanie_pokaz->next;
                    }

                }


                temp->temp = temp->temp->next;

            }

            temp = temp->next ;
        }
    }


};







int main() {



    Struktura* testowa_struktura = new Struktura;
    testowa_struktura->add_sznur('A','A','A');
    testowa_struktura->add_koral('A','A','A',100 );
    testowa_struktura->add_koral('A','A','A',200 );
    testowa_struktura->add_koral('A','A','A',300 );
    testowa_struktura->add_koral('A','A','A',400 );
    testowa_struktura->add_koral('A','A','A',500 );
    testowa_struktura->add_koral('A','A','A',600 );
    testowa_struktura->add_koral('A','A','A',700 );

    testowa_struktura->dodaj_wiazanie_z_a_do_b_i_z_b_do_a(100,300,'A', 'A','A','A','A','A');
    testowa_struktura->pokaz_wszystko_P_na_czysto();


    Koral* skrt = new Koral;
    skrt = nullptr;
    //cout << skrt << endl;







    char input_polecenie = '\0';
    Struktura* potezna_struktura = new Struktura;

    char x0;
    char x1;
    char x2;

    char y0;
    char y1;
    char y2;

    short id_korala_x=0;
    short id_korala_y=0;


    while (input_polecenie != 'F' )
    {
        cout <<endl;

        cin >> input_polecenie ;


        //cout << " flaga 1 " << endl;

        if ( input_polecenie == 'S' )
        {

            //cout << " flaga 2 " << endl;
            cin >> x0 >> x1 >> x2 ;

            potezna_struktura->add_sznur(x0,x1,x2);

        } else if ( input_polecenie == 'B' )
        {

            cin >>id_korala_x >>x0 >> x1 >> x2 ;
            potezna_struktura->add_koral(x0,x1,x2,id_korala_x);


        } else if ( input_polecenie == 'L' )
        {

            cin >>id_korala_x >>x0 >> x1 >> x2 >> id_korala_y>> y0 >> y1 >> y2 ;
            potezna_struktura->dodaj_wiazanie_z_a_do_b_i_z_b_do_a(id_korala_x,id_korala_y,x0,x1,x2,y0,y1,y2);
            //cout << " wiazania 100 bbb : " << potezna_struktura->first->next->first->pierwsze_wiazanie->id_korala <<endl;
            //cout << " wiazania 300 aaa : " << potezna_struktura->first->first->next->next->pierwsze_wiazanie->id_korala <<endl;

        } else if ( input_polecenie == 'U' )
        {


            cin >>id_korala_x >>x0 >> x1 >> x2 >> id_korala_y>> y0 >> y1 >> y2 ;
            potezna_struktura->usun_wiazanie_z_a_do_b(id_korala_x,id_korala_y,x0,x1,x2,y0,y1,y2);

        } else if ( input_polecenie == 'D' )
        {

            cin >> id_korala_x >> x0 >> x1 >>x2 ;
            potezna_struktura->usun_korala_z_jego_powiazaniami(x0,x1,x2,id_korala_x) ;



        } else if ( input_polecenie == 'M' )
        {
            cin >> id_korala_x >> x0 >> x1 >> x2 >> y0 >> y1 >> y2 ;
            potezna_struktura->przenosiny_korala( id_korala_x,x0,x1,x2,y0,y1,y2) ;



        } else if ( input_polecenie == 'R' )
        {
            cin >> x0 >> x1 >> x2 ;
            potezna_struktura->usuniecie_sznura_z_koralami_i_ich_wiazaniami(x0,x1,x2) ;

        } else if ( input_polecenie == 'P' )
        {
            //cout << " flaga 3 " << endl;
            //potezna_struktura->pokaz_wszystko_P();
            potezna_struktura->pokaz_wszystko_P_na_czysto();
            //cout << " flaga 4 " << endl;



        }



    }



    cout << "Hello, World!" << endl;


        return 0;
}


