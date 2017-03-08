#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L) = nil;
    //----------------------------------------
}

address alokasi(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;

    info(P) = x;
    next(P) = nil;
    prev(P) = nil;

    //----------------------------------------
    return P;
}

void dealokasi(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if(first(L) == nil)
    {
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = last(L);
        prev(first(L)) = P;
        next(last(L)) = P;
        first(L) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if(first(L) == nil)
    {
        insertFirst(L,P);
    }
    else
    {
        next(P) = first(L);
        prev(P) = last(L);
        prev(first(L)) = P;
        next(last(L))= P;
        last(L) = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    P = first(L);
    while(info(P).ID != x.ID && next(P) != first(L))
    {
        P = next(P);
    }
    if(info(P).ID == x.ID)
    {
        return P;
    }
    else
    {
        return nil;
    }
    //----------------------------------------

}
address findElmByName(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    P = first(L);
    while(info(P).name != x.name && next(P) != first(L))
    {
        P = next(P);
    }

    if(info(P).name == x.name)
    {
        return P;
    }
    else
    {
        return nil;
    }
    //----------------------------------------

}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) != nil)
    {
        P = first(L);
        if(next(P) == first(L))
        {
            first(L) = nil;
            last(L) = nil;
        }
        else
        {
            first(L) = next(P);
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
            next(P) = nil;
            prev(P) = nil;
        }
    }
    else
    {
        cout<<"List Kosong \n";
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) != nil)
    {
        P = first(L);
        if(next(P) == first(L))
        {
            first(L) = nil;
            last(L) = nil;
        }
        else
        {
            address Q = first(L);
            while(next(next(Q)) != first(L))
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
            prev(first(L)) = Q;
            last(L) = Q;
            next(P) = nil;
            prev(P) = nil;
        }
    }
    else
    {
        cout<<"List Kosong \n";
    }

    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if(first(L) == nil)
    {
        insertFirst(L,P);
    }
    else if(first(L) == last(L))
    {
        insertLast(L,P);

    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(P))= P;
        next(Prec) = P;
        if(Prec == last(L))
        {
            first(L) = P;
        }
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L) != nil)
    {
        if(next(Prec) == first(L))
        {
            deleteFirst(L,P);
        }
        else if(next(Prec) == last(L))
        {
            deleteLast(L,P);
        }
        else
        {
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = nil;
            prev(P) = nil;
        }
    }
}
//----------------------------------------


