#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const int MAX_MOKINIU = 100;
    const int MAX_PAZYMIU = 10;

    // Masyvai
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuSk[MAX_MOKINIU] = {0}; // Kiekvieno mokinio pažymiu kiekis

    int mokiniuSk = 0; // Dabartinis mokiniu skaicius
    int pasirinkimas;

    do {
        cout << "\n=== MOKINIU PAŽYMIU SISTEMA ===\n";
        cout << "1. Ivesti mokini ir jo pažymius\n .";
        cout << "2. Peržiureti visu mokiniu pažymius\n";
        cout << "3. Peržiureti konkretaus mokinio pažymius\n";
        cout << "4. Atnaujinti pažymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pašalinti mokini\n";
        cout << "7. Išeiti\n";
        cout << "Pasirinkite veiksma (1-7): ";
        
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida: iveskite skaiciu nuo 1 iki 7.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (pasirinkimas) {
            case 1: { // Ivesti mokini ir jo pažymius
                if (mokiniuSk >= MAX_MOKINIU) {
                    cout << "Pasiektas maksimalus mokiniu limitas (100).\n";
                    break;
                }

                cout << "Iveskite mokinio varda: ";
                cin >> vardai[mokiniuSk];

                cout << "Kiek pažymiu norite ivesti šiam mokiniui (1-10)? ";
                int kiek;
                cin >> kiek;

                if (kiek < 1 || kiek > MAX_PAZYMIU) {
                    cout << "Neteisingas pažymiu skaicius. Turi buti nuo 1 iki 10.\n";
                    break;
                }

                pazymiuSk[mokiniuSk] = kiek;
                cout << "Iveskite " << kiek << " pažymius (nuo 1 iki 10):\n";
                for (int i = 0; i < kiek; i++) {
                    int p;
                    cin >> p;
                    if (p < 1 || p > 10) {
                        cout << "Neteisingas pažymys! Iveskite skaiciu nuo 1 iki 10 iš naujo: ";
                        i--; // Pakartoti ši žingsni
                    } else {
                        pazymiai[mokiniuSk][i] = p;
                    }
                }
                mokiniuSk++;
                cout << "Mokinys sekmingai pridetas!\n";
                break;
            }
            case 2: { // Peržiureti visu mokiniu pažymius
                if (mokiniuSk == 0) {
                    cout << "Sarašas tušcias – nera mokiniu.\n";
                    break;
                }
                cout << "\n--- Visu mokiniu sarašas ---\n";
                for (int i = 0; i < mokiniuSk; i++) {
                    cout << i + 1 << ". " << vardai[i] << " - Pažymiai: ";
                    if (pazymiuSk[i] == 0) {
                        cout << "nera pažymiu";
                    } else {
                        for (int j = 0; j < pazymiuSk[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << "\n";
                }
                break;
            }
            case 3: { // Peržiureti konkretaus mokinio pažymius
                if (mokiniuSk == 0) {
                    cout << "Sarašas tušcias.\n";
                    break;
                }
                cout << "Iveskite mokinio numeri (nuo 1 iki " << mokiniuSk << "): ";
                int ind;
                cin >> ind;

                if (ind < 1 || ind > mokiniuSk) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << mokiniuSk << ".\n";
                    break;
                }

                int idx = ind - 1;
                cout << "Mokinys: " << vardai[idx] << "\nPažymiai: ";
                for (int j = 0; j < pazymiuSk[idx]; j++) {
                    cout << pazymiai[idx][j] << " ";
                }
                cout << "\n";
                break;
            }
            case 4: { // Atnaujinti pažymi
                if (mokiniuSk == 0) {
                    cout << "Sarašas tušcias.\n";
                    break;
                }
                cout << "Iveskite mokinio numeri (nuo 1 iki " << mokiniuSk << "): ";
                int mIdx;
                cin >> mIdx;

                if (mIdx < 1 || mIdx > mokiniuSk) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << mokiniuSk << ".\n";
                    break;
                }
                int mIndex = mIdx - 1;

                if (pazymiuSk[mIndex] == 0) {
                    cout << "Šis mokinys neturi pažymiu.\n";
                    break;
                }

                cout << "Iveskite pažymio numeri, kuri norite keisti (nuo 1 iki " << pazymiuSk[mIndex] << "): ";
                int pIdx;
                cin >> pIdx;

                if (pIdx < 1 || pIdx > pazymiuSk[mIndex]) {
                    cout << "Neteisingas pažymio numeris. Iveskite skaiciu nuo 1 iki " << pazymiuSk[mIndex] << ".\n";
                    break;
                }
                int pIndex = pIdx - 1;

                cout << "Dabartinis pažymys: " << pazymiai[mIndex][pIndex] << "\nIveskite nauja pažymi (1-10): ";
                int naujasP;
                cin >> naujasP;

                if (naujasP < 1 || naujasP > 10) {
                    cout << "Neteisingas pažymys! Turi buti nuo 1 iki 10.\n";
                } else {
                    pazymiai[mIndex][pIndex] = naujasP;
                    cout << "Pažymys sekmingai atnaujintas!\n";
                }
                break;
            }
            case 5: { // Apskaiciuoti mokinio vidurki
                if (mokiniuSk == 0) {
                    cout << "Sarašas tušcias.\n";
                    break;
                }
                cout << "Iveskite mokinio numeri (nuo 1 iki " << mokiniuSk << "): ";
                int ind;
                cin >> ind;

                if (ind < 1 || ind > mokiniuSk) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << mokiniuSk << ".\n";
                    break;
                }

                int idx = ind - 1;
                if (pazymiuSk[idx] == 0) {
                    cout << "Mokinys neturi pažymiu, vidurkio paskaiciuoti negalima.\n";
                    break;
                }

                double suma = 0;
                for (int j = 0; j < pazymiuSk[idx]; j++) {
                    suma += pazymiai[idx][j];
                }
                double vidurkis = suma / pazymiuSk[idx];

                cout << "Mokinio " << vardai[idx] << " pažymiu vidurkis: " 
                     << fixed << setprecision(2) << vidurkis << "\n";
                break;
            }
            case 6: { // Pašalinti mokini
                if (mokiniuSk == 0) {
                    cout << "Sarašas tušcias.\n";
                    break;
                }
                cout << "Iveskite šalinamo mokinio numeri (nuo 1 iki " << mokiniuSk << "): ";
                int ind;
                cin >> ind;

                if (ind < 1 || ind > mokiniuSk) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << mokiniuSk << ".\n";
                    break;
                }

                int idx = ind - 1;
                // Perstumiami duomenys per viena pozicija atgal
                for (int i = idx; i < mokiniuSk - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuSk[i] = pazymiuSk[i + 1];
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }
                mokiniuSk--;
                cout << "Mokinys sekmingai pašalintas iš sarašo.\n";
                break;
            }
            case 7:
                cout << "Programa baigia darba. Viso gero!\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 7.\n";
        }
    } while (pasirinkimas != 7);

    return 0;
}