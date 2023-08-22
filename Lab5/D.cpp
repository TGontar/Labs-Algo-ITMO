//#include "iostream"
//#include "string"
//#include "math.h"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
//using std::vector;
//using std::to_string;
//
//struct BinaryTree {
//
//    struct Node {
//        int value;
//        Node *left;
//        Node *right;
//        Node *parent;
//    };
//
//    Node *root;
//    Node *tmp;
//
//    BinaryTree() : root(nullptr), tmp(nullptr) {}
//
//
//    Node *createNode(int val, Node *left, Node *right, Node *parent) {
//        Node *q;
//        q = new Node;
//        q->value = val;
//        q->left = left;
//        q->right = right;
//        q->parent = parent;
//        return q;
//    }
//
//    Node *createTree(int val) {
//        root = createNode(val, nullptr, nullptr, nullptr);
//        return root;
//    }
//
//    Node *searchElement(Node *x, int k) {
//        if (x == nullptr || k == x->value) {
//            return x;
//        }
//        if (k < x->value) {
//            return searchElement(x->left, k);
//        } else {
//            return searchElement(x->right, k);
//        }
//    }
//
//    Node *insertElement(Node *x, int z) {
//        if (x == nullptr) {
//            return createTree(z);
//        }
//        while (x != nullptr) {
//            if (z > x->value) {
//                if (x->right != nullptr) {
//                    x = x->right;
//                } else {
//                    Node *newnode = createNode(z, nullptr, nullptr, x);
//                    x->right = newnode;
//                    return newnode;
//                }
//            } else if (z < x->value) {
//                if (x->left != nullptr) {
//                    x = x->left;
//                } else {
//                    Node *newnode = createNode(z, nullptr, nullptr, x);
//                    x->left = newnode;
//                    return newnode;
//                }
//            }
//        }
//        return nullptr;
//    }
//
//    Node *findMin(Node *x) {
//        if (x->left == nullptr) {
//            return x;
//        }
//
//        return findMin(x->left);
//    }
//
//    Node *findMax(Node *x) {
//        if (x->right == nullptr) {
//            return x;
//        }
//
//        return findMax(x->right);
//    }
//
//    int findNextInt(Node *x, int k) {
//        if (x == nullptr) {
//            return k;
//        }
//        Node *current = x;
//        Node *successor = x;
//        while (current != nullptr) {
//            if (current->value <= k) {
//                current = current->right;
//            } else {
//                successor = current;
//                current = current->left;
//            }
//        }
//        return successor->value;
//    }
//
//    int findPrevInt(Node *x, int k) {
//        if (x == nullptr) {
//            return k;
//        }
//        Node *current = x;
//        Node *successor = x;
//        while (current != nullptr) {
//            if (current->value >= k) {
//                current = current->left;
//            } else {
//                successor = current;
//                current = current->right;
//            }
//        }
//        return successor->value;
//    }
//
//    Node *deleteNode(Node *x, int z) {
//        if (x == nullptr) {
//            return x;
//        }
//        if (z < x->value) {
//            x->left = deleteNode(x->left, z);
//        } else if (z > x->value) {
//            x->right = deleteNode(x->right, z);
//        } else if (x->left != nullptr && x->right != nullptr) {
//            x->value = (findMin(x->right))->value;
//            x->right = deleteNode(x->right, x->value);
//        } else {
//            if (x->left != nullptr) {
//                x = x->left;
//            } else if (x->right != nullptr) {
//                x = x->right;
//            } else {
//                x = nullptr;
//            }
//        }
//        return x;
//    }
//
//    bool isBinaryTree(Node *x, int min, int max) {
//        if (x == nullptr) {
//            return true;
//        }
//        if (x->value <= min || x->value >= max) {
//            return false;
//        }
//        return isBinaryTree(x->left, min, x->value) && isBinaryTree(x->right, x->value, max);
//    }
//
//};
//
//
//int main() {
//    BinaryTree tree1;
//    vector<string> ans;
//    while (true) {
//        string str;
//        cin >> str;
//        if (str.empty()) {
//            break;
//        } else {
//            if (str[0] == 'i') {
//                int v;
//                cin >> v;
//                tree1.tmp = tree1.searchElement(tree1.root, v);
//                if (tree1.tmp == nullptr) {
//                tree1.insertElement(tree1.root, v);
//                }
//            } else if (str[0] == 'd') {
//                int v;
//                cin >> v;
//                tree1.tmp = tree1.deleteNode(tree1.root, v);
//                tree1.root = tree1.tmp;
//                if (tree1.root != nullptr) {
//                    tree1.root->parent = nullptr;
//                }
//            } else if (str[0] == 'e') {
//                int v;
//                cin >> v;
//                tree1.tmp = tree1.searchElement(tree1.root, v);
//                if (tree1.tmp != nullptr) {
//                    ans.push_back("true");
//                } else {
//                    ans.push_back("false");
//                }
//            } else if (str[0] == 'n') {
//                int v;
//                cin >> v;
//                int next = tree1.findNextInt(tree1.root, v);
//                if (next > v) {
//                    ans.push_back(to_string(next));
//                } else {
//                    ans.push_back("none");
//                }
//            } else if (str[0] == 'p') {
//                int v;
//                cin >> v;
//                int prev = tree1.findPrevInt(tree1.root, v);
//                if (prev < v) {
//                    ans.push_back(to_string(prev));
//                } else {
//                    ans.push_back("none");
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//    return 0;
//}