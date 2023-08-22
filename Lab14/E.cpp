//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//#include "regex"
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//using std::getline;
//using std::regex_match;
//using std::regex;
//
////check if the input string is correct
//bool check_if_correct(vector<string> &req) {
//    if (req.size() != 8) {
//        return false;
//    }
//
//    regex name("^([A-Z])([a-z]*)$");
//    if (!regex_match(req[0], name) or !regex_match(req[1], name) or !regex_match(req[2], name)) {
//        return false;
//    }
//
//    regex age("^[0-9]{2}$");
//    if (!regex_match(req[3], age)) {
//        return false;
//    }
//
//    regex phone_number(R"(^((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$)");
//    if (!regex_match(req[4], phone_number)) {
//        return false;
//    }
//
//    regex city("^(g.)[A-Z][A-Z][A-Z],$");
//    if (!regex_match(req[5], city)) {
//        return false;
//    }
//
//    regex street("^(ul.)[A-Z]([a-z]*),$");
//    if (!regex_match(req[6], street)) {
//        return false;
//    }
//
//    regex house("^(d.)([0-9]+)$");
//    if (!regex_match(req[7], house)) {
//        return false;
//    }
//
//    return true;
//}
//
//
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int q;
//    cin >> q;
//    string trash{};
//    getline(cin, trash);
//
//    vector<string> ans;
//    for (int num = 0; num < q; num++) {
//        vector<string> request;
//
//        string inp{};
//        getline(cin, inp);
//
//        string tmp = {};
//        for (int i = 0; i < inp.size(); i++) {
//            if (inp[i] == ' ') {
//                request.emplace_back(tmp);
//                tmp = {};
//            } else {
//                tmp.push_back(inp[i]);
//            }
//        }
//        request.emplace_back(tmp);
//
//        if (check_if_correct(request)) {
//            ans.emplace_back("YES");
//        } else {
//            ans.emplace_back("NO");
//        }
//
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}