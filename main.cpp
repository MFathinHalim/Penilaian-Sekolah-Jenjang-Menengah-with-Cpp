#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
using namespace std;

string gradeFunction(double avg)
{
    if (avg >= 95)
        return "\x1b[32mA+";
    else if (avg >= 90)
        return "\x1b[32mA";
    else if (avg >= 80)
        return "\x1b[33mB";
    else if (avg >= 70)
        return "\x1b[33mC";
    else if (avg >= 60)
        return "\x1b[31mD";
    else
        return "\x1b[31mF";
}

void printAsciiBanner()
{
    cout << R"(
 ________  _____ ______   ________  ________   ________  ________          ________  ___          
|\   ____\|\   _ \  _   \|\   __  \|\   ___  \|\   ____\|\   __  \        |\   __  \|\  \         
\ \  \___|\ \  \\\__\ \  \ \  \|\  \ \  \\ \  \ \  \___|\ \  \|\  \       \ \  \|\  \ \  \        
 \ \_____  \ \  \\|__| \  \ \   __  \ \  \\ \  \ \_____  \ \   __  \       \ \   _  _\ \  \       
  \|____|\  \ \  \    \ \  \ \  \ \  \ \  \\ \  \|____|\  \ \  \ \  \       \ \  \\  \\ \  \____  
    ____\_\  \ \__\    \ \__\ \__\ \__\ \__\\ \__\____\_\  \ \__\ \__\       \ \__\\ _\\ \_______\
   |\_________\|__|     \|__|\|__|\|__|\|__| \|__|\_________\|__|\|__|        \|__|\|__|\|_______|
   \|_________|                                  \|_________|)" << endl;
}

void printBoxedMessage(const string& msg)
{
    string border(msg.size() + 4, '=');
    cout << "\n" << border << endl;
    cout << "| " << msg << " |" << endl;
    cout << border << "\n" << endl;
}

int main()
{
    vector<string> mapel;
    vector<double> nilaiList;
    string jenjang;

    printAsciiBanner();
    printBoxedMessage("Selamat datang di program penilaian siswa!");
    cout << "Program ini akan meminta input nilai siswa untuk jenjang pendidikan SMP atau SMA." << endl;
    cout << "Silakan masukkan nilai untuk setiap mata pelajaran yang relevan.\n" << endl;

    string namaSiswa, kelasSiswa;
    cout << "\x1b[36mMasukkan nama siswa: \x1b[0m";
    getline(cin, namaSiswa);

    cout << "\x1b[36mMasukkan kelas " << namaSiswa << ": \x1b[0m";
    getline(cin, kelasSiswa);

    if (namaSiswa.empty() || kelasSiswa.empty())
    {
        printBoxedMessage("\x1b[31mNama siswa dan kelas tidak boleh kosong.\x1b[0m");
        cout << "\nTekan Enter untuk keluar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    while (true)
    {
        cout << "\x1b[36mMasukkan jenjang pendidikan (SMP/SMA) Negeri: \x1b[0m";
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
            printBoxedMessage("\x1b[31mJenjang tidak dikenali. Harus SMP atau SMA.\x1b[0m");
            continue;
        }
        break;
    }

    printBoxedMessage("Penilaian Mata Pelajaran");

    double sum = 0;
    for (const string& m : mapel)
    {
        double nilai;
        while (true)
        {
            cout << "Nilai \x1b[32m" << m << "\x1b[0m: ";
            cin >> nilai;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\x1b[31mInput tidak valid. Masukkan angka.\n\x1b[0m";
                continue;
            }

            if (nilai < 0 || nilai > 100)
            {
                cout << "\x1b[31mNilai harus antara 0 dan 100.\n\x1b[0m";
                continue;
            }

            break;
        }

        nilaiList.push_back(nilai);
        sum += nilai;
    }

    cout << "\n+----------------------------+--------+" << endl;
    cout << "| Mata Pelajaran            | Nilai  |" << endl;
    cout << "+----------------------------+--------+" << endl;
    for (size_t i = 0; i < mapel.size(); i++)
    {
        cout << "| " << setw(26) << left << mapel[i]
             << "| " << setw(6) << right << nilaiList[i] << " |" << endl;
    }
    cout << "+----------------------------+--------+" << endl;

    double avg = sum / mapel.size();

    printBoxedMessage("Hasil Penilaian");

    cout << "Rata-rata nilai \x1b[33m" << namaSiswa << "\x1b[0m dari kelas \x1b[33m" << kelasSiswa << "\x1b[0m: " << avg << endl;
    cout << "Grade: " << gradeFunction(avg) << "\x1b[0m" << endl;

    printBoxedMessage("\x1b[36mTekan Enter untuk keluar...\x1b[0m");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}