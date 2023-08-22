//#include "iostream"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::vector;
//using std::string;
//
//struct Node {
//    int number;
//    int value;
//    Node *left;
//    Node *right;
//    Node *parent;
//
//};
//
//struct BinaryTree {
//    Node *root;
//    Node **currentarr;
//    BinaryTree() : root(nullptr), currentarr(nullptr) {};
//
//    Node *create_node(int num, int val, Node *l, Node *r, Node *p) {
//        Node *q = new Node;
//        q->number = num;
//        q->value = val;
//        q->left = l;
//        q->right = r;
//        q->parent = p;
//
//        return q;
//    }
//
//
//
//    //make tree out of an array
//    Node *make_tree(int arr[], int n) {
//        currentarr = new Node * [n];
//        root = create_node(1, arr[0], nullptr, nullptr, nullptr);
//        Node *current = root;
//        currentarr[0] = current;
//
//        for (int i = 0; i < n; i++) {
//            current = currentarr[i];
//
//            if (i * 2 + 1 < n) {
//                current->left = create_node(i * 2 + 2, arr[i * 2 + 1], nullptr, nullptr, current);
//                currentarr[i * 2 + 1] = current->left;
//            }
//            if (i * 2 + 2 < n) {
//                current->right = create_node(i * 2 + 3, arr[i * 2 + 2], nullptr, nullptr, current);
//                currentarr[i * 2 + 2] = current->right;
//            }
//
//        }
//
//        return root;
//    }
//
//    //find node with its number
//    void find_node(Node * &ans, int num) {
//        ans = currentarr[num-1];
//    }
//
//    //change the tree using algorithm
//    void change(Node *v) {
//        if (v == root or v == nullptr) {
//            return;
//        } else {
//            if (v->parent->left == v) {
//
//                Node *tempp = v->parent;
//                Node *tempvl = v->left;
//                if (v->parent->parent == nullptr) {
//                    root = v;
//                    v->parent = nullptr;
//                    v->left = tempp;
//                    tempp->parent = v;
//
//                    tempp->left = tempvl;
//                    if (tempvl != nullptr) {
//                        tempvl->parent = tempp;
//                    }
//                    return;
//                }
//
//                if (v->parent->parent->left == v->parent) {
//                    v->parent->parent->left = v;
//                    v->parent = tempp->parent;
//                } else {
//                    v->parent->parent->right = v;;
//                    v->parent = tempp->parent;
//                }
//
//                v->left = tempp;
//                tempp->parent = v;
//
//                tempp->left = tempvl;
//                if (tempvl != nullptr) {
//                    tempvl->parent = tempp;
//                }
//            } else {
//
//                Node *tempp = v->parent;
//                Node *tempvl = v->right;
//                if (v->parent->parent == nullptr) {
//                    root = v;
//                    v->parent = nullptr;
//                    v->right = tempp;
//                    tempp->parent = v;
//
//                    tempp->right = tempvl;
//                    if (tempvl != nullptr) {
//                        tempvl->parent = tempp;
//                    }
//                    return;
//                }
//
//                if (v->parent->parent->left == v->parent) {
//                    v->parent->parent->left = v;
//                    v->parent = tempp->parent;
//                } else {
//                    v->parent->parent->right = v;;
//                    v->parent = tempp->parent;
//                }
//
//                v->right = tempp;
//                tempp->parent = v;
//
//                tempp->right = tempvl;
//                if (tempvl != nullptr) {
//                    tempvl->parent = tempp;
//                }
//            }
//        }
//
//        return;
//    }
//
//    //make a left-right-verticle traversal
//    void LRVtrav(Node *current, vector<int> &arr) {
//        if (current != nullptr) {
//            LRVtrav(current->left, arr);
//            LRVtrav(current->right, arr);
//            arr.push_back(current->value);
//        }
//    }
//
//};
//
////decode final message
//void RLEdecode(vector<int> &letters, vector<int> &coeffs, int n) {
//    for (int i = 0; i < n; i++) {
//        cout << string(coeffs[i], letters[i]);
//    }
//}
//
//
//int main() {
//    //input coeffs
//    int n;
//    cin >> n;
//    int Q1;
//    cin >> Q1;
//
//    int *coeffs = new int[n];
//    for (int i = 0; i < n; i++) {
//        cin >> coeffs[i];
//    }
//
//    int *opscoeffs = new int[n];
//    for (int i = 0; i < Q1; i++) {
//        cin >> opscoeffs[i];
//    }
//
//    //input letters
//    cin >> n;
//    int Q2;
//    cin >> Q2;
//
//    unsigned char *letters = new unsigned char [n];
//    for (int i = 0; i < n; i++) {
//        cin >> letters[i];
//    }
//    int *normletters = new int[n];
//    for (int i = 0; i < n; i++) {
//        normletters[i] = (int) (letters[i]);
//    }
//    delete [] letters;
//
//    int *opsletters = new int[n];
//    for (int i = 0; i < Q2; i++) {
//        cin >> opsletters[i];
//    }
//
//    //fill the trees
//    BinaryTree treecoeffs;
//    treecoeffs.make_tree(coeffs, n);
//
//    BinaryTree treeletters;
//    treeletters.make_tree(normletters, n);
//
//
//    //make changes
//    for (int i = 0; i < Q1; i++) {
//        Node *changing = nullptr;
//        treecoeffs.find_node(changing, opscoeffs[i]);
//        if (changing == nullptr) {
//            continue;
//        } else {
//            treecoeffs.change(changing);
//        }
//    }
//
//    for (int i = 0; i < Q2; i++) {
//        Node *changing = nullptr;
//        treeletters.find_node(changing, opsletters[i]);
//        if (changing == nullptr) {
//            continue;
//        } else {
//            treeletters.change(changing);
//        }
//    }
//
//
//
//    //print answers
//    vector<int> anscoeffs;
//    treecoeffs.LRVtrav(treecoeffs.root, anscoeffs);
//
//    vector<int> ansletters;
//    treeletters.LRVtrav(treeletters.root, ansletters);
//
//    RLEdecode(ansletters, anscoeffs, n);
//
//    //delete dynamic arrays
//    delete [] coeffs;
//    delete [] normletters;
//    delete [] opscoeffs;
//    delete [] opsletters;
//
//    return 0;
//}
