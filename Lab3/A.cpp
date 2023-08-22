//#include "iostream"
//#include "string"
//#include "vector"
//
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
////using std::endl;
//
//struct Queue {
//
//    struct Node {
//        int value;
//        Node *next;
//    };
//
//    Node *top;
//    Node *low;
//    Queue():top(nullptr), low(nullptr) {}
//
//    void push(int v) {
//        Node *q;
//        q = new Node;
//        q->value = v;
//        q->next = nullptr;
//        if (top == nullptr) {
//            top = q;
//            low = q;
//        } else {
//            top->next = q;
//            top = q;
//        }
//    }
//
//    int pop() {
//        if (low == nullptr) {
//            exit(0);
//        }
//        if (low == top) {
//            Node *q = low;
//            int ret = q->value;
//            free(q);
//            top = nullptr;
//            low = nullptr;
//            return ret;
//        } else {
//            Node *q = low;
//            int ret = q->value;
//            low = q->next;
//            free(q);
//            return ret;
//        }
//    }
//
//    void printst() {
//        while (low != nullptr) {
//            Node *q = low;
//            cout << q->value << "\n";
//            low = q->next;
//        }
//    }
//};
//int main() {
//    Queue queue1 = {};
//    int n;
//    cin >> n;
//    vector<int> ans;
//    for (int i = 0; i < n; i++) {
//        char a;
//        cin >> a;
//        if (a == 43) { //чар значение плюса
//            int val;
//            cin >> val;
//            queue1.push(val);
//        } else {
//            int elem = queue1.pop();
//            ans.push_back(elem);
//        }
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//
//    return 0;
//}