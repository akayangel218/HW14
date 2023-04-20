#include <iostream>
#include <vector>

using namespace std;

vector<int> minmax(vector<int> n, int start, int end) {
    
    // 1 element
    if (n.size() == 1) {
        return n;
    }

    // 2 elements
    else if (n.size() == 2) {
        vector<int> elem;
        if (n[0] > n[1]) {
            elem.push_back(n[start]);
            elem.push_back(n[end]);
            return elem;
        }
        else {
            elem.push_back(n[0]);
            elem.push_back(n[1]);
            return elem;
        }
    }

    // 3+ elements
    else {
        vector<int> result, elem1, elem2;
        int nustart;
        int nuend;
        elem1 = minmax(n, start, (end / 2));
        elem2 = minmax(n, (end + 1 / 2) + (end + 1 % 2), end);

        // compare min
        if (elem1[0] < elem2[0]) {
            result.push_back(elem1[0]);
        }
        else {
            result.push_back(elem2[0]);
        }
        // compare max
        if (elem1.size() == 1) {
            if (elem1[0] < elem2[1]) {
                result.push_back(elem2[1]);
            }
        }
        else if (elem2.size() == 1) {
            if (elem1[1] > elem2[0]) {
                result.push_back(elem1[1]);
            }
        }
        else if (elem1.size() > 1 && elem2.size() > 1) {
            if (elem1[1] > elem2[1]) {
                result.push_back(elem1[1]);
            }
            else {
                result.push_back(elem2[1]);
            }
        }
        return result;
    }
}

int main() {

    vector<int> test1, test2, test3, result1, result2, result3;
    test1.push_back(14);

    // case 1: 1 element
    result1 = minmax(test1, 0, test1.size() - 1);
    cout << "The minimum and maximum are " << result1[0] << endl;

    // case 2: 2 elements
    test2.push_back(50);
    test2.push_back(29);
    result2 = minmax(test2, 0, test1.size() - 1);
    cout << "The minimum and maximum are " << result2[0] << "&" << result2[1] << endl;

    // case 3: 3+ elements (odd)
    /*for (int i = 0; i < 9) {

    }*/

    // case 4: 3+ elements (even)

    // case 4: 
    test3.clear();
    result3.clear();
    return 0;
}