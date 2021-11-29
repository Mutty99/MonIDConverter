#include <iostream>
using namespace std;

int main() {
    int64_t TID, SID, G7TID, G7SID, FULLID, TSV, TRV;
    int mode;
    bool runtime = true;
    while (runtime) {
        cout << "MAIN MENU:\n1) Input Generation 3-6 IDs\n2) Input Generation 7 IDs\nPress any other button to exit.\n\n";
        cin >> mode;
        switch (mode) {
            case 1: {
                cout << "\nInsert TID:\n";
                cin >> TID;
                cout << "Insert SID:\n";
                cin >> SID;

                FULLID = SID << 16 | TID;
                G7TID = FULLID % 1000000;
                G7SID = FULLID / 1000000;
                TSV = (SID ^ TID) >> 4;
                TRV = (TID ^ SID) & 0xF;

                cout << "\nTID: " << TID << endl << "SID: " << SID << endl << "TSV: " << TSV << endl;
                cout << "TRV: " << TRV << endl << "G7TID: " << G7TID << endl << "G7SID: " << G7SID << "\n\n";
                system("pause");
                runtime = false;
                break;
            }
            case 2: {
                cout << "\nInsert G7TID:\n";
                cin >> G7TID;
                cout << "Insert G7SID:\n";
                cin >> G7SID;

                SID = ((G7SID * 1000000) + G7TID) / 65536;
                TID = ((G7SID * 1000000) + G7TID) % 65536;
                TSV = (SID ^ TID) >> 4;
                TRV = (TID ^ SID) & 0xF;

                cout << "\nTID: " << TID << endl << "SID: " << SID << endl << "TSV: " << TSV << endl;
                cout << "TRV: " << TRV << endl << "G7TID: " << G7TID << endl << "G7SID: " << G7SID << "\n\n";
                system("pause");
                runtime = false;
                break;
            }
            default: {
                runtime = false;
                break;
            }
        }
    }
    return 0;
}
