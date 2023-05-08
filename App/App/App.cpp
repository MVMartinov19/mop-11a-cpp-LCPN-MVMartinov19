#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void backtrack(string path, int index, string digits, unordered_map<char, string> letters, vector<string>& combinations)
{
    if (path.length() == digits.length()) {
        combinations.push_back(path);
        return;
    }

    auto& chars = letters[digits[index]];

    for (auto c : chars)
    {
        path.push_back(c);
        backtrack(path, index + 1, digits, letters, combinations);

        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {};
    }

    unordered_map<char, string> letters =
    {
        {'1', " "}, {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> combinations;

    backtrack("", 0, digits, letters, combinations);

    return combinations;
}

void printVector(vector<string> v)
{
    cout << "[";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }

    cout << "]" << endl;
}

int main() {
    vector<string> digits = { "16", "96", "576" };
    int counter = 1;
    for (auto& digit : digits)
    {
        cout << counter << ".\t All letter combinations for '" << digits[counter - 1] << "' : ";
        counter++;
        printVector(letterCombinations(digit));
        cout << string(100, '-') << endl;
    }
}