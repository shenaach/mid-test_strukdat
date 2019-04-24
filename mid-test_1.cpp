/*
Nama Program : Mid Test 1
Nama : Sharashena Chairani
NPM : 140810180022
Tanggal Buat : 24 April 2019
Deskripsi : Ascending dan Update Jumlah Makanan
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ElemtList{
 int harga;
 int jumlah;
 char nama[40];
 char pemesan[30];
 ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru=new ElemtList;
    cout << "~~~Welcome to Restoran LALALA~~~"<<endl;
    cout << "Jumlah Makanan	:";cin >>pBaru->jumlah;
    cout << "Nama Pemesan	:";cin >>pBaru->pemesan; 
    cout << "Nama Makanan	:";cin >>pBaru->nama; 
    cout << "Harga			:";cin >>pBaru->harga;
    //cin.getline(pBaru->nama, 50);
 pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
  First=pBaru;
  else{
   pBaru->next=First;
   First=pBaru;
  }
}

void traversal(List First){
    pointer pBantu;
 pBantu=First;
 cout << "Jumlah makanan \t"<< "Nama Pemesan\t"<< "Nama Makanan\t"<<"Harga\t"<<endl;
 while(pBantu != NULL){
        cout <<pBantu->jumlah<<"\t"<<pBantu->pemesan<<"\t"<<pBantu->nama<<"\t"<<pBantu->harga<<endl;
  pBantu=pBantu->next;
 }
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void insertLast(List& First, pointer pBaru){

    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
    }
    last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    cout << "Delete last"<<endl;
    if (First==NULL){
        pHapus=NULL;
        cout << "List Kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=NULL;
        while(last->next !=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}


void insertAfter(List& First,pointer pCari,pointer pBaru){
    if (pCari->next==NULL)
        pCari->next=pBaru;
    else {
        pBaru->next=pCari->next;
        pCari->next=pBaru;
    }
}


void linearSearch(List First,int key, int& found, pointer& pCari){
    found=0;
    pCari=First;
    while (found==0 && pCari!=NULL) {
        if (pCari->jumlah ==key)
            found=1;
        else
        pCari=pCari->next;
        }

}

void update(List& First, int key) {
  pointer pToUpdate = NULL;
  cout << "Jumlah Makanan: "; cin >> pToUpdate->jumlah;
  cout << endl;
}

void sorting(List& First){
  int count = 0, i;
  pointer start,curr,trail,temp;
  start=First;
  curr=NULL;
  trail=NULL;
  temp=NULL;

  while(start != NULL) { 
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) { 

    curr = trail = First; 

    while (curr->next != NULL) { 
      if (curr->jumlah > curr->next->jumlah) { 

        temp = curr->next; 
        curr->next = curr->next->next;
        temp->next = curr;

        
        if(curr == First) 
          First = trail = temp;
        else 
          trail->next = temp;
        curr = temp; 
      }

      trail = curr;
      curr = curr->next;
    }
  }
}


int main()
{
    pointer p,pCari;
    List m;
    int ketemu;
    int kunci;
    int pilih;

    createList(m);
    while(1){
        system("cls");
        cout<<"Silahkan Pilih Menu"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Update "<<endl;
        cout<<"3. Tampilkan"<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Masukan Pilihan Anda : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(m, p);
            sorting(m);
        break;

        case 2:
            cout<<"\nMasukkan Jumlah Makanan : "; cin>>kunci;
            linearSearch(m,kunci,ketemu,pCari);
            if (ketemu){
                cout<<"Ditemukan yang dicari "<<endl;
                update(m,kunci);
            }
            else {
                cout<<" Tidak Ditemukan yang dicari "<<endl;
            }
        break;

        case 3:
            traversal(m);
        break;

        case 4:
            return 0;
            break;
        }
        system("pause");
    }

    return 0;
}
