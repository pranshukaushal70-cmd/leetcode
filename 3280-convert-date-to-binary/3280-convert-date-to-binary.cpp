string toBinary(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += (n % 2) + '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        string y = toBinary(year);
        string m = toBinary(month);
        string d = toBinary(day);
        return y + "-" + m + "-" + d;
    }
};