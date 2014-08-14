/*
 * Given a string of digits, find the minimum number of additions required for the string to equal some target number. Each addition is the equivalent of inserting a plus sign somewhere into the string of digits.
 * After all plus signs are inserted, evaluate the sum as usual. For example, consider the string "12" (quotes for clarity). With zero additions, we can achieve the number 12. If we insert one plus sign into the string,
 * we get "1+2", which evaluates to 3. So, in that case, given "12", a minimum of 1 addition is required to get the number 3.
 * As another example, consider "303" and a target sum of 6. The best strategy is not "3+0+3", but "3+03". You can do this because leading zeros do not change the result.
 *
 * Write a class QuickSums that contains the method minSums, which takes a String numbers and an int sum.
 * The method should calculate and return the minimum number of additions required to create an expression from numbers that evaluates to sum. If this is impossible, return -1.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int minSums(string str, const int result, int level, int adds);

int evalResult(const string& str);

int main() {

    string str;
    int result;

    while(true) {

        cout << "String: ";
        cin >> str;
        if(str == "x")
            break;
        cout << "Result: ";
        cin >> result;

        cout << "Min adds needed : " << minSums(str, result, 1, 0) << endl;
    }

    return 0;
}

int minSums(string str, const int result, int level, int adds) {

    if(evalResult(str) == result)
        return adds;

    if(level > str.length() - 1)
        return -1;

    int retVal = -1;
    for(int i = level; i < str.length(); i++) {
        str.insert(i, "+");
        int tmp = minSums(str, result, i + 2, adds + 1);
        if (tmp > -1 && (tmp < retVal || retVal == -1))
           retVal = tmp;
        str.erase(i, 1);
    }

    return retVal;

}

int evalResult(const string& str) {

    int num = 0;
    int i = 0;

    for(i = 0; i < str.length(); ++i) {
        if(str[i] != '+')
            num = num*10 + (str[i] - '0');
        else
            break;
        }
    if(i < str.length()) {

        string s = str;
        s.erase(0, i+1);
        num += evalResult(s);
    }

    return num;

}
