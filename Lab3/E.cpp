//#include "iostream"
//#include "string"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
////using std::endl;
//using std::vector;
//
//struct Stack {
//
//    struct Node {
//        int value;
//        Node *next;
//    };
//
//    Node *top;
//    Stack(): top(nullptr){}
//
//    void push(int v) {
//        Node *q;
//        q = new Node;
//        q->value = v;
//        q->next = nullptr;
//        if (top == nullptr) {
//            top = q;
//        } else {
//            q->next = top;
//            top = q;
//        }
//    }
//
//    int pop() {
//        if (top == nullptr) {
//            exit(0);
//        } else {
//            Node *q = top;
//            top = q->next;
//            int ret = q->value;
//            free(q);
//            return ret;
//
//        }
//    }
//
//    void printst() {
//        while (top != nullptr) {
//            Node *q = top;
//            cout << q->value << "\n";
//            top = q->next;
//        }
//    }
//
//    string isempty() {
//        if (top == nullptr) {
//            return "YES";
//        } else {
//            return "NO";
//        }
//    }
//
//    int last_elem() {
//        if (top != nullptr) {
//            return top->value;
//        }
//    }
//
//
//};
//
//
//int main() {
//    Stack stack1;
//    Stack maxstack;
//    int n;
//    cin >> n;
//    vector<int> ans;
//    for (int i = 0; i < n; i++) {
//        string a;
//        cin >> a;
//        if (a[0] == '+') { //чар значение плюса
//            int val;
//            cin >> val;
//            stack1.push(val);
//            if (maxstack.isempty() == "YES") {
//                maxstack.push(val);
//            } else if (maxstack.last_elem() >= val) {
//               maxstack.push(maxstack.last_elem());
//            } else {
//               maxstack.push(val);
//            }
//        } else if (a[0] == '-') { //чар значение минуса
//            stack1.pop();
//            maxstack.pop();
//        } else {
//            int maximum = maxstack.last_elem();
//            ans.push_back(maximum);
//        }
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}
