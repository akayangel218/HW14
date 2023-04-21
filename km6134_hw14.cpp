#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minmax(vector<int> n) {
    
    // 1 element
    if (n.size() == 1) {
        return n;
    }

    // 2 elements
    else if (n.size() == 2) {
        vector<int> elem;
        if (n[0] > n[1]) {
            elem.push_back(n[1]);
            elem.push_back(n[0]);
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
        vector<int> result, h1, h2, elem1, elem2;
        int mid = n.size() / 2;
        if (n.size() % 2 != 0) {
            mid++;
        }
        for (int i = 0; i < mid; i++) {
            h1.push_back(n[i]);
        }

        for (int j = mid; j < n.size(); j++) {
            h2.push_back(n[j]);
        }
        elem1 = minmax(h1);
        elem2 = minmax(h2);

        // compare min
        if (elem1[0] < elem2[0]) {
            result.push_back(elem1[0]);
        }
        else {
            result.push_back(elem2[0]);
        }
        // compare max
        if (elem1.size() > 1 && elem2.size() > 1) {
            if (elem1[1] > elem2[1]) {
                result.push_back(elem1[1]);
            }
            else {
                result.push_back(elem2[1]);
            }
        }
        else if (elem1.size() == 1) {
            if (elem1[0] > elem2[1]) {
                result.pop_back();
                result.push_back(elem2[1]);
                result.push_back(elem1[0]);
            }
            else {
                result.push_back(elem2[1]);
            }
        }
        else if (elem2.size() == 1) {
            if (elem1[1] < elem2[0]) {
                result.pop_back();
                result.push_back(elem1[1]);
                result.push_back(elem2[0]);
            }
            else {
                result.push_back(elem1[1]);
            }
        }
        return result;
    }
}

int main() {
    srand (time(NULL));
    vector<int> test1, test2, test3, result1, result2, result3;
    test1.push_back(14);

    // case 1: 1 element
    result1 = minmax(test1);
    cout << "Test 1: {" << test1[0] << "}" << endl;
    cout << "The minimum and maximum for test 1 is '" << result1[0] << "'" << endl << endl;

    // case 2: 2 elements
    test2.push_back(50);
    test2.push_back(29);
    cout << "Test 2: {";
    for (int i = 0; i < test2.size(); i++) {
        cout << test2[i] << ", ";
    }
    cout << '}' << endl;
    result2 = minmax(test2);
    cout << "The minimum and maximum for test 2 are '" << result2[0] << "' & '" << result2[1] << "'" << endl << endl;

    // case 3: 3+ elements (odd)
    for (int i = 0; i < 9; i++) {
        int random = 1 + (rand() % 100);
        if (find(test3.begin(), test3.end(), random) == test3.end()) {
            test3.push_back(random);
        }
        else {
            i--;
        }
    }
    cout << "Test 3: {";
    for (int i = 0; i < test3.size(); i++) {
        cout << test3[i] << ", ";
    }
    cout << '}' << endl;
    result3 = minmax(test3);
    cout << "The minimum and maximum for test 3 are '" << result3[0] << "' & '" << result3[1] << "'" << endl << endl;


    test3.clear();
    result3.clear();

    // case 4: 3+ elements (even)
    for (int i = 0; i < 10; i++) {
        int random = 1 + (rand() % 100);
        if (find(test3.begin(), test3.end(), random) == test3.end()) {
            test3.push_back(random);
        }
        else {
            i--;
        }
    }
    
    cout << "Test 4: {";
    for (int i = 0; i < test3.size(); i++) {
        cout << test3[i] << ", ";
    }
    cout << '}' << endl;
    result3 = minmax(test3);
    cout << "The minimum and maximum for test 4 are '" << result3[0] << "' & '" << result3[1] << "'" << endl;
    return 0;
}