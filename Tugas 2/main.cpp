// Nama: Zhario Aditya
// NIM: 1120031039;

#include <iostream>
#include <stdlib.h>


using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
};

TNode *head, *tail; // deklarasi variabel pointer head dan tail untuk menunjukkan head dan tail

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        tail->next = tail;
    } else {
        nodeBaru->next = head;
        head = nodeBaru;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        tail->next = tail;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus;
    int d;

    if (isEmpty() == 0) {
        nodeHapus = head;
        d = nodeHapus->data;

        if (head != tail) {
            nodeHapus = head;
            head = head->next;
            tail->next = head;
            delete nodeHapus;
        } else {
            head = NULL;
            tail = NULL;
        }
		cout << "Data " << d << " berhasil dihapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head == tail) {
            d = tail->data;
            head = NULL;
            tail = NULL;
        } else {
            nodeBantu = head;

            while (nodeBantu->next != tail) {
                nodeBantu = nodeBantu->next;
            }

            nodeHapus = tail;
            tail = nodeBantu;
            d = nodeHapus->data;
            tail->next = head;
            delete nodeHapus;
        }
		cout << "Data " << d << " berhasil dihapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    if (isEmpty() == 0) {
        nodeBantu = head;

        while (nodeBantu->next != head) {
            nodeHapus = nodeBantu;
            nodeBantu = nodeBantu->next;
            delete nodeHapus;
        }

        head = NULL;
        tail = NULL;
    }

    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != tail->next);
    } else {
        cout << "List masih kosong" << endl;
    }
}

void cariDataTertentu() {
	int i;
	bool ditemukan = false;
	TNode *nodeBantu;
    nodeBantu = head;

    if (isEmpty() == 0) {
	    cout<<"Masukan data yang ingin dicari = ";
	    cin>>i;

        do {
        	if(i == nodeBantu->data) {
        		ditemukan = true;
        		break;
			}
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != tail->next);

        if(ditemukan) {
	        cout << "Data ditemukan : " << endl;
	        cout << nodeBantu->data << endl;
		} else {
			cout << "Data tidak ditemukan";
		}
    } else {
        cout << "Data anda tidak tersedia" << endl;
    }

}

void hapusTertentu() {
	int i;
	bool ditemukan = false;
	TNode *nodeHapus, *nodeBantu;
    nodeHapus = head;


    if (isEmpty() == 0) {
	    cout<<"Masukan data yang ingin dihapus = ";
	    cin>>i;

        do {
        	if(i == nodeHapus->data) {
        		ditemukan = true;
        		break;
			}
            nodeHapus = nodeHapus->next;
        } while (nodeHapus != tail->next);

        if(ditemukan) {
        	if(nodeHapus == head) {
        		hapusDepan();
			} else if(nodeHapus == tail) {
        		hapusBelakang();
			} else {
				if(head->next == nodeHapus) {
					head->next = nodeHapus->next;
				} else {
					nodeBantu = head;
					do {
						nodeBantu = nodeBantu->next;
					} while (nodeBantu->next != nodeHapus);

					nodeBantu->next = nodeHapus->next;
				}

				delete nodeHapus;
				cout << "Data " << i << " berhasil dihapus" << endl;
			}
		} else {
			cout << "Data tidak ditemukan";
		}
    } else {
        cout << "Data anda tidak tersedia" << endl;
    }

}


int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ======================================="<<endl;
        cout<<" =         SLLC WITH HEAD & TAIL       ="<<endl;
        cout<<" =      1120031039 - Zhario Aditya     ="<<endl;
        cout<<" ======================================="<<endl;
        cout<<" = 1. Insert Depan                     ="<<endl;
        cout<<" = 2. Insert Belakang                  ="<<endl;
        cout<<" = 3. Hapus Depan                      ="<<endl;
        cout<<" = 4. Hapus Belakang                   ="<<endl;
        cout<<" = 5. Tampil Data                      ="<<endl;
        cout<<" = 6. Hapus semua Data                 ="<<endl;
        cout<<" = 7. Cari Data Tertentu               ="<<endl;
        cout<<" = 8. Hapus Data Tertentu              ="<<endl;
        cout<<" = 9. Exit                             ="<<endl;
        cout<<" ======================================="<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if(cin.fail()){
	    cout<<"\n Maaf, Inputan Harus Berupa Angka!";
            cin.clear();
            cin.ignore();
		} else if (pil == 1) {
            cout<<" Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<" Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        } else if (pil == 6) {
            hapusSemua();
        } else if (pil == 7) {
            cariDataTertentu();
        } else if (pil == 8) {
            hapusTertentu();
        } else if (pil != 9) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 9);

    return 0;
}
