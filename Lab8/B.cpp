//#include "iostream"
//#include "vector"
//
//
//using std::cin;
//using std::cout;
//using std::vector;
//
//struct RLEletter {
//    char symbol;
//    int count;
//};
//
//int main() {
//
//    int n, m, k;
//    cin >> n;
//    cin >> m;
//    cin >> k;
//
//    char *masha = new char [n];
//    char *sasha = new char [m];
//
//    for (int i = 0; i < n; i++) {
//        cin >> masha[i];
//    }
//
//    for (int i = 0; i < m; i++) {
//        cin >> sasha[i];
//    }
//
//
//    vector<RLEletter> mashanormal;
//    for (int i = 0; i < n; i++) {
//        if (masha[i] > 47 and masha[i] < 58) {
//            mashanormal[mashanormal.size()-1].count = mashanormal[mashanormal.size()-1].count * 10 + (masha[i] - '0');
//        } else {
//            mashanormal.push_back(RLEletter {masha[i], 0});
//        }
//    }
//
//    vector<RLEletter> sashanormal;
//    for (int i = 0; i < m; i++) {
//        if (sasha[i] > 47 and sasha[i] < 58) {
//            sashanormal[sashanormal.size()-1].count = sashanormal[sashanormal.size()-1].count * 10 + (sasha[i] - '0');
//        } else {
//            sashanormal.push_back(RLEletter {sasha[i], 0});
//        }
//    }
//
//    delete [] masha;
//    delete [] sasha;
//
//    int razl = 0;
//
//
//    int i = 0;
//    int j = 0;
//
//    while (i != mashanormal.size() and j != sashanormal.size()) {
//
//        if (mashanormal[i].count >= sashanormal[j].count) {
//            mashanormal[i].count -= sashanormal[j].count;
//            if (mashanormal[i].symbol != sashanormal[j].symbol) {
//                razl += sashanormal[j].count;
//            }
//            j += 1;
//            if (mashanormal[i].count == 0) {
//                i += 1;
//            }
//        } else {
//            sashanormal[j].count -= mashanormal[i].count;
//            if (sashanormal[j].symbol != mashanormal[i].symbol) {
//                razl += mashanormal[i].count;
//            }
//            i += 1;
//            if (sashanormal[j].count == 0) {
//                j += 1;
//            }
//        }
//
//    }
//
//    if (razl < k) {
//        cout << "Yes";
//    } else {
//        cout << "No";
//    }
//
//    return 0;
//}