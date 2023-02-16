#include <iostream>
#include <conio.h>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct KTP{
	long long int nik;
	string nama;
	string ttl;
	string jenis_kelamin;
	string agama;
	string status;
	string pekerjaan;
	KTP *next;
}*kepala, *tail, *nodeBaru, *cur, *del;;

class Node{
	public :
		void buatNode();
		void tambahAwal();
		void tambahTengah(int);
		void tambahAkhir();
		void hapusAwal();
		void hapusAkhir();
		void hapusTengah(int);
		void cetak();
		void programdata();
	private :
		long long int a;
		string b,c,d,e,f,g;
		int pil;
};


//pembuatan circular linklist terlebih dahulu
void Node::buatNode(){
	cout<<"===========Pembuatan Node kepala terlebih dahulu===========\n";
	kepala = new KTP();
	cout<<"masukkan nik : ";cin>>a;cin.ignore(1, '\n');
	cout<<"masukkan nama : ";getline(cin, b);
	cout<<"masukkan tempat/Tgl lahir : ";getline(cin, c);
	cout<<"masukkan jenis kelamin : ";cin>>d;
	cout<<"masukkan Agama : ";cin>>e;cin.ignore(1, '\n');
	cout<<"masukkan status perkawinan saat ini : ";getline(cin, f);
	cout<<"masukkan pekerjaan : ";cin>>g;
	cout<<"\n";
	kepala->nik=a;
	kepala->nama=b;
	kepala->ttl=c;
	kepala->jenis_kelamin=d;
	kepala->agama=e;
	kepala->status=f;
	kepala->pekerjaan=g;
	tail = kepala;
	tail->next = kepala;
} 

// penambahan diawal
void Node::tambahAwal(){
	if( kepala == NULL ){
    	cout << "Buat Linked List dulu!!" << endl;
	}else{
	    nodeBaru = new KTP();
	    cout<<"masukkan nik : ";cin>>a;cin.ignore(1, '\n');
		cout<<"masukkan nama : ";getline(cin, b);
		cout<<"masukkan tempat/Tgl lahir : ";getline(cin, c);
		cout<<"masukkan jenis kelamin : ";cin>>d;
		cout<<"masukkan Agama : ";cin>>e;cin.ignore(1, '\n');
		cout<<"masukkan status perkawinan saat ini : ";getline(cin, f);
		cout<<"masukkan pekerjaan : ";cin>>g;
		cout<<"\n";
		nodeBaru->nik=a;
		nodeBaru->nama=b;
		nodeBaru->ttl=c;
		nodeBaru->jenis_kelamin=d;
		nodeBaru->agama=e;
		nodeBaru->status=f;
		nodeBaru->pekerjaan=g;
	    nodeBaru->next = kepala;
	    tail->next = nodeBaru;
	    kepala = nodeBaru;
	}
}

// penambahan dibelakang
void Node::tambahAkhir(){
	if( kepala == NULL ){
    	cout << "Buat Linked List dulu!!" << endl;
	}else{
		nodeBaru = new KTP();
		cout<<"masukkan nik : ";cin>>a;cin.ignore(1, '\n');
		cout<<"masukkan nama : ";getline(cin, b);
		cout<<"masukkan tempat/Tgl lahir : ";getline(cin, c);
		cout<<"masukkan jenis kelamin : ";cin>>d;
		cout<<"masukkan Agama : ";cin>>e;cin.ignore(1, '\n');
		cout<<"masukkan status perkawinan saat ini : ";getline(cin, f);
		cout<<"masukkan pekerjaan : ";cin>>g;
		cout<<"\n";
		nodeBaru->nik=a;
		nodeBaru->nama=b;
		nodeBaru->ttl=c;
		nodeBaru->jenis_kelamin=d;
		nodeBaru->agama=e;
		nodeBaru->status=f;
		nodeBaru->pekerjaan=g;
		nodeBaru->next = kepala;
		tail->next = nodeBaru;
		tail = nodeBaru;
	}
}

//penambahan ditengah
void Node::tambahTengah(int posisi)
{
  if( kepala == NULL ){
    	cout << "Buat Linked List dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      	cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
	    nodeBaru = new KTP();
	    cout<<"masukkan nik : ";cin>>a;cin.ignore(1, '\n');
		cout<<"masukkan nama : ";getline(cin, b);
		cout<<"masukkan tempat/Tgl lahir : ";getline(cin, c);
		cout<<"masukkan jenis kelamin : ";cin>>d;
		cout<<"masukkan Agama : ";cin>>e;cin.ignore(1, '\n');
		cout<<"masukkan status perkawinan saat ini : ";getline(cin, f);
		cout<<"masukkan pekerjaan : ";cin>>g;
		cout<<"\n";
		nodeBaru->nik=a;
		nodeBaru->nama=b;
		nodeBaru->ttl=c;
		nodeBaru->jenis_kelamin=d;
		nodeBaru->agama=e;
		nodeBaru->status=f;
		nodeBaru->pekerjaan=g;

		// tranversing
		int nomor = 1;
		cur = kepala;
		while (nomor < posisi - 1){
			cur = cur->next;
			nomor++;
		}
		nodeBaru->next = cur->next;
		cur->next = nodeBaru;
    }
  }
}

// hapus awal
void Node::hapusAwal(){
  if( kepala == NULL ){
    cout << "Link list kosong" << endl;
  }else{
    del = kepala;
    kepala = kepala->next;
    tail->next = kepala;
    delete del;
    cout<<"berhasil dihapus";
  }
}

//hapus akhir
void Node::hapusAkhir()
{
  if( kepala == NULL ){
    cout << "Link list kosong" << endl;
  }else{
    del = tail;
    cur = kepala;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = kepala;
    delete del;
    cout<<"berhasil dihapus";
  }
}

//hapus ditengah
void Node::hapusTengah(int posisi)
{
  if( kepala == NULL ){
    cout << "Link list kosong" << endl;
  }else{
    //algoritma untuk transversing
    int nomor = 1;
    cur = kepala;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
    cout<<"berhasil dihapus";
  }
}


void Node::cetak()
{
  if( kepala == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << "______________________Data KTP_______________________\n";
    cur = kepala;
    while (cur->next != kepala)
    {
      // print
    	cout<<"=================================================\n";
		cout<<"NIK\t\t\t: "<<cur->nik<<endl;
		cout<<"Nama\t\t\t: "<<cur->nama<<endl;
		cout<<"tempat/Tgl Lahir\t: "<<cur->ttl<<endl;
		cout<<"Jenis kelamin\t\t: "<<cur->jenis_kelamin<<endl;
		cout<<"Agama\t\t\t: "<<cur->agama<<endl;
		cout<<"Status Perkawinan\t: "<<cur->status<<endl;
		cout<<"Pekerjaan\t\t: "<<cur->pekerjaan<<endl;
		cout<<"=================================================\n\n";
      	cur = cur->next;
    }
    cout<<"=================================================\n";
	cout<<"NIK\t\t\t: "<<cur->nik<<endl;
	cout<<"Nama\t\t\t: "<<cur->nama<<endl;
	cout<<"tempat/Tgl Lahir\t: "<<cur->ttl<<endl;
	cout<<"Jenis kelamin\t\t: "<<cur->jenis_kelamin<<endl;
	cout<<"Agama\t\t\t: "<<cur->agama<<endl;
	cout<<"Status Perkawinan\t: "<<cur->status<<endl;
	cout<<"Pekerjaan\t\t: "<<cur->pekerjaan<<endl;
	cout<<"=================================================\n\n";
    cout << endl;
    cout << "__________________Batas Akhir______________________\n";
  }
}

void Node::programdata(){ //fungsi utama untuk menjalankan
	int tengah;
	while (1){ //while(1) agar setelah klik getch selalu mengembalikan ke program ini
		system("cls");
		cout<<"=============Data KTP=================\n";
		cout<<"1. menampilkan data\n";
		cout<<"2. menambahkan data (didepan)\n";
		cout<<"3. menambah data (dibelakang)\n";
		cout<<"4. menambah data (ditengah)\n";
		cout<<"5. hapus data (didepan)\n";
		cout<<"6. hapus data (dibelakang)\n";
		cout<<"7. hapus data (ditengah)\n";
		cout<<"Masukkan pilihan\n";cin>>pil;
		if(pil==1){
			cetak();
			getch();
		}
		else if (pil==2){
			tambahAwal();
			getch();
		}
		else if (pil==3){
			tambahAkhir();
			getch();
		}
		else if (pil==4){
			cout<<"masukkan data keberapa akan data ktp akan dimasukkan : ";cin>>tengah;
			tambahTengah(tengah);
			getch();
		}
		else if (pil==5){
			hapusAwal();
			getch();
		}
		else if(pil==6){
			hapusAkhir();
			getch();
		}
		else if(pil==7){
			cout<<"masukkan data keberapa data ktp akan dihapus : ";cin>>tengah;
			hapusTengah(tengah);
			getch();
		}
		else{
			cout<<"data yang dimasukkan salah\n";
			getch();
		}
	}
}

int main(){
	Node ktp;
	ktp.buatNode();
	ktp.programdata();

}
