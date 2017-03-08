#include "player.h"


void printInfo(List L)
{
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */
    if(first(L) != nil)
    {
        address Q = first(L);
        do
        {
            cout<<"name    : "<<info(Q).name<<endl
                <<"ID      : "<<info(Q).ID<<endl
                <<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        }
        while(Q!=first(L));
        cout<<"==============================================="<<endl;
    }
    else
    {
        cout<<"List Kosong"<<endl;
        cout<<endl;

    }
}


void playMusic(address P)
{
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void shuffleList(List &L)
{
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------


    //----------------------------------------
}

void sortListByID(List &L)
{
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    address P = first(L);
    address Q;
    cout<<"(1.) Sort by Ascending "<<endl;
    cout<<"(2.) Sort by Descending "<<endl;
    cout<<"Masukkan Pilihan: "<<endl;
    int z;
    cin>>z;
    if(z == 1)
    {
        while(next(P) != first(L))
        {
            if(info(P).ID < info(next(P)).ID)
            {
                Q = next(P);
                deleteAfter(L,P,Q);
                insertFirst(L,Q);
            }
            else
            {
                P = next(P);
            }
        }
    }
    else if(z == 2)
    {
        while(next(P) != first(L))
        {
            if(info(P).ID > info(next(P)).ID)
            {
                Q = next(P);
                deleteAfter(L,P,Q);
                insertFirst(L,Q);
            }
            else
            {
                P = next(P);
            }
        }
    }else{
        cout<<"Wrong Input"<<endl;
    }

    //----------------------------------------

}

void playRepeat(List &L, int n)
{
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
    address P = first(L);
    int i = 0;
    while (i < n)
    {
        playMusic(P);
        P = next(P);
        if(P == last(L))
        {
            i++;
        }

    }
}

//----------------------------------------


void deleteMusicByID(List &L, infotype x)
{
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
    * FS : elemen dengan ID yang dicari didealokasi
    */
    //-------------your code here-------------
    address P;
    address Prec = nil;
    P = findElmByID(L,x);
    if(P != nil)
    {
        Prec = prev(P);
        deleteAfter(L,Prec,P);
        cout<<"ID: "<<info(P).ID<<endl;
        cout<<"Berhasil Dihapus!!"<<endl;
        dealokasi(P);

        cout<<"Press [ENTER] to continue";
        cout<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"ID TIDAK ADA \n";
    }
    //----------------------------------------

}
