#include <iostream>
#include <limits>
#include <vector>
using namespace std;

string gradeFunction(double avg)
{
    if (avg >= 95)
        return "\x1b[32m A+";
    else if (avg >= 90)
        return "\x1b[32m A";
    else if (avg >= 80)
        return "B";
    else if (avg >= 70)
        return "\x1b[33m C";
    else if (avg >= 60)
        return "\x1b[31m D";
    else
        return "\x1b[31m F";
}

int main()
{
    vector<string> mapel; // pake vector, bukan array
    string jenjang;
    cout << "\x1b[33m" << "Selamat datang di program penilaian siswa! \n"
         << endl;
    cout << "\x1b[0m" << "========================" << endl;
    cout << "Program ini akan meminta input nilai siswa untuk jenjang pendidikan SMP atau SMA." << endl;
    cout << "Silakan masukkan nilai untuk setiap mata pelajaran yang relevan." << endl;
    cout << "======================== \n"
         << endl;

    string namaSiswa;
    cout << "\x1b[36m" << "Masukkan nama siswa: " << "\x1b[0m";
    getline(cin, namaSiswa);

    string kelasSiswa;
    cout << "\x1b[36m" << "Masukkan kelas " << namaSiswa << ": " << "\x1b[0m";
    getline(cin, kelasSiswa);
    cout << endl;

    if (namaSiswa.empty() || kelasSiswa.empty())
    {
        cout << "\x1b[31m" << "Nama siswa dan kelas tidak boleh kosong.\n"
             << "\x1b[0m";
        cout << "\nTekan Enter untuk keluar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    while (true)
    {
        cout << "\x1b[36m" << "Masukkan jenjang pendidikan (SMP/SMA) Negeri: " << "\x1b[0m";
        cin >> jenjang;
        if (jenjang == "SMP")
        {
            mapel = {"Matematika", "IPA", "IPS", "Seni Budaya", "Bahasa Indonesia", "Bahasa Inggris", "Prakarya", "Pendidikan Pancasila", "Pendidikan Agama"};
        }
        else if (jenjang == "SMA")
        {
            mapel = {"Matematika", "Fisika", "Kimia", "Biologi", "Sejarah", "Geografi", "Ekonomi", "Sosiologi", "Informatika", "Pemrograman", "Bahasa Indonesia", "Bahasa Inggris", "Prakarya", "Pendidikan Pancasila", "Pendidikan Agama", "PJOK"};
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\x1b[31m" << "Jenjang tidak dikenali. Harus SMP atau SMA.\x1b[0m\n"
                 << endl;
            continue;
        }
        break;
    }

    cout << "\n========================" << endl;
    cout << "\x1b[33m" << "Penilaian Mata Pelajaran" << "\x1b[0m" << endl;
    cout << "========================\n"
         << endl;

    double sum = 0;
    int jumlahMapel = mapel.size();
    for (int i = 0; i < jumlahMapel; i++)
    {
        double nilai;

        while (true)
        {
            cout << "Nilai " << "\x1b[32m" << mapel[i] << "\x1b[0m" << ": ";
            cin >> nilai;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\x1b[31m" << "Input tidak valid. Masukkan angka.\n"
                     << "\x1b[0m";
                continue;
            }

            if (nilai < 0 || nilai > 100)
            {
                cout << "\x1b[31m" << "Nilai harus antara 0 dan 100.\n"
                     << "\x1b[0m";
                continue;
            }

            break;
        }
        sum += nilai;
    }

    cout << "\n========================" << endl;
    cout << "\x1b[32m" << "Hasil Penilaian" << "\x1b[0m" << endl;
    cout << "========================\n"
         << endl;

    double avg = sum / jumlahMapel;
    cout << "Rata-rata nilai " << namaSiswa << " dari kelas " << kelasSiswa << ": " << avg << endl;
    cout << "Grade " << namaSiswa << " dari kelas " << kelasSiswa << ": " << gradeFunction(avg) << "\x1b[0m" << endl;

    cout << "\nTekan Enter untuk keluar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
