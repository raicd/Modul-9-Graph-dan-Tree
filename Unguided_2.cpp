#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Pohon
{
    char data;
    Pohon *kiri, *kanan, *induk;
};

Pohon *akar;

void inisialisasi()
{
    akar = NULL;
}

bool kosong()
{
    return akar == NULL;
}

Pohon *buatNodeBaru(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->kiri = NULL;
    node->kanan = NULL;
    node->induk = NULL;
    return node;
}

void buatAkar(char data)
{
    if (kosong())
    {
        akar = buatNodeBaru(data);
        cout << "\nNode " << data << " berhasil dibuat sebagai akar." << endl;
    }
    else
    {
        cout << "\nPohon sudah ada." << endl;
    }
}

Pohon *tambahKiri(char data, Pohon *node)
{
    if (kosong())
    {
        cout << "\nBuat pohon terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kiri != NULL)
        {
            cout << "\nNode " << node->data << " sudah memiliki anak kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *nodeBaru = buatNodeBaru(data);
            nodeBaru->induk = node;
            node->kiri = nodeBaru;
            cout << "\nNode " << data << " berhasil ditambahkan sebagai anak kiri dari " << node->data << endl;
            return nodeBaru;
        }
    }
}

Pohon *tambahKanan(char data, Pohon *node)
{
    if (kosong())
    {
        cout << "\nBuat pohon terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kanan != NULL)
        {
            cout << "\nNode " << node->data << " sudah memiliki anak kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *nodeBaru = buatNodeBaru(data);
            nodeBaru->induk = node;
            node->kanan = nodeBaru;
            cout << "\nNode " << data << " berhasil ditambahkan sebagai anak kanan dari " << node->data << endl;
            return nodeBaru;
        }
    }
}

void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

void inOrder(Pohon *node)
{
    if (node != NULL)
    {
        inOrder(node->kiri);
        cout << " " << node->data << ", ";
        inOrder(node->kanan);
    }
}

void postOrder(Pohon *node)
{
    if (node != NULL)
    {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << " " << node->data << ", ";
    }
}

void tampilkanAnak(Pohon *node)
{
    if (node != NULL)
    {
        cout << "Induk: " << node->data << endl;
        if (node->kiri != NULL)
        {
            cout << "Anak Kiri: " << node->kiri->data << endl;
        }
        else
        {
            cout << "Anak Kiri: (tidak punya anak kiri)" << endl;
        }
        if (node->kanan != NULL)
        {
            cout << "Anak Kanan: " << node->kanan->data << endl;
        }
        else
        {
            cout << "Anak Kanan: (tidak punya anak kanan)" << endl;
        }
    }
}

void tampilkanKeturunan(Pohon *node)
{
    if (node != NULL)
    {
        cout << "Keturunan dari " << node->data << ": ";
        queue<Pohon *> q;
        if (node->kiri != NULL)
            q.push(node->kiri);
        if (node->kanan != NULL)
            q.push(node->kanan);
        while (!q.empty())
        {
            Pohon *sementara = q.front();
            q.pop();
            cout << sementara->data << " ";
            if (sementara->kiri != NULL)
                q.push(sementara->kiri);
            if (sementara->kanan != NULL)
                q.push(sementara->kanan);
        }
        cout << endl;
    }
}

Pohon *cariNode(Pohon *node, char data)
{
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;
    Pohon *hasilKiri = cariNode(node->kiri, data);
    if (hasilKiri != NULL)
        return hasilKiri;
    return cariNode(node->kanan, data);
}

int main()
{
    int pilihan;
    char data;
    inisialisasi();

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Akar\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan PreOrder\n";
        cout << "5. Tampilkan InOrder\n";
        cout << "6. Tampilkan PostOrder\n";
        cout << "7. Tampilkan Anak Node\n";
        cout << "8. Tampilkan Keturunan Node\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data untuk akar: ";
            cin >> data;
            buatAkar(data);
            break;
        case 2:
        {
            cout << "Masukkan data untuk node kiri: ";
            cin >> data;
            cout << "Masukkan data induk: ";
            char dataInduk;
            cin >> dataInduk;
            Pohon *induk = cariNode(akar, dataInduk);
            if (induk != NULL)
            {
                tambahKiri(data, induk);
            }
            else
            {
                cout << "\nInduk tidak ditemukan!" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Masukkan data untuk node kanan: ";
            cin >> data;
            cout << "Masukkan data induk: ";
            char dataInduk;
            cin >> dataInduk;
            Pohon *induk = cariNode(akar, dataInduk);
            if (induk != NULL)
            {
                tambahKanan(data, induk);
            }
            else
            {
                cout << "\nInduk tidak ditemukan!" << endl;
            }
            break;
        }
        case 4:
            cout << "\nPreOrder: ";
            preOrder(akar);
            cout << "\n";
            break;
        case 5:
            cout << "\nInOrder: ";
            inOrder(akar);
            cout << "\n";
            break;
        case 6:
            cout << "\nPostOrder: ";
            postOrder(akar);
            cout << "\n";
            break;
        case 7:
            cout << "Masukkan data node untuk menampilkan anak: ";
            cin >> data;
            {
                Pohon *node = cariNode(akar, data);
                if (node != NULL)
                {
                    tampilkanAnak(node);
                }
                else
                {
                    cout << "\nNode tidak ditemukan!" << endl;
                }
            }
            break;
        case 8:
            cout << "Masukkan data node untuk menampilkan keturunan: ";
            cin >> data;
            {
                Pohon *node = cariNode(akar, data);
                if (node != NULL)
                {
                    tampilkanKeturunan(node);
                }
                else
                {
                    cout << "\nNode tidak ditemukan!" << endl;
                }
            }
            break;
        case 9:
            return 0;
        default:
            cout << "Opsi tidak valid! Coba lagi." << endl;
        }
    }

    return 0;
}
