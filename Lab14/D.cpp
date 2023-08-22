//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//#include "map"
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//using std::pair;
//using std::stoi;
//using std::map;
//
//struct Node {
//    map<char, Node *> next;
//    bool isTerminal;
//    int count;
//    int wordCount;
//};
//
//struct BOR {
//    Node *root;
//    int totalnumber;
//
//    BOR() {
//        root = new Node{{}, false, 0, 0};
//        totalnumber = 0;
//    }
//
//    //insert a word into bor
//    void insert_word(string &inp) {
//        Node *current = root;
//
//        for (int i = 0; i < inp.size(); i++) {
//            if (current->next.find(inp[i]) == current->next.end()) {
//                current->next[inp[i]] = new Node{{}, false, 0, 0};
//            }
//
//            current = current->next[inp[i]];
//            current->count += 1;
//        }
//
//        current->isTerminal = true;
//        current->wordCount+= 1;
//        totalnumber += 1;
//    }
//
//    //find string
//    string inorder_traversal(int index) {
//        if (index > totalnumber) {
//            return "";
//        }
//
//        Node *current = root;
//        string answer;
//        int curindex = 0;
//
//        while (curindex < index) {
//            for (auto &i : current->next) {
//                if (curindex + i.second->count >= index) {
//                    answer.push_back(i.first);
//                    current = i.second;
//                    if (current->isTerminal) {
//                        curindex += current->wordCount;
//                    }
//                    break;
//                } else {
//                    curindex += i.second->count;
//                }
//            }
//        }
//
//        return answer;
//    }
//};
//
//signed main() {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    BOR bor1 = BOR();
//
//    for (int i = 0; i < n; i+= 1) {
//        string s;
//        cin >> s;
//        if (s[0] >= 'a' and s[0] <= 'z') {
//            bor1.insert_word(s);
//        } else {
//            int k = stoi(s);
//
//            string found_word = bor1.inorder_traversal(k);
//            cout << found_word << '\n';
//        }
//    }
//
//    return 0;
//}
