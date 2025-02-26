#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

/*
* This program explores the use of STL map, multimap & lambda functions
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
//int mapMain() {
    // Create map personHeight. Key: name, Value: height
    std::map<string, int> personHeight = {
        {"Alice", 165},
        {"Bob", 175},
        {"David", 180},
        {"Charlie", 168}
    };

    pair<string, int> p1 = { "John", 180 };
    personHeight.insert(p1);
    string s = "Jane";
    personHeight.insert({s, 175});

    // Iterate over personHeight and print data
    std::cout << "Person Heights (Name -> Height):" << endl;
    for (const auto& pair : personHeight) {
        cout << pair.first << " -> " << pair.second << endl;
    }



    // Create multimap heightPerson. Key: height, Value: name
    multimap<int, string> heightPerson;

    // Insert data from personHeight into heightPerson
    for (const auto& pair : personHeight) {
        heightPerson.insert({ pair.second, pair.first });
    }

    pair<int, string> p(168, "Joe");
    heightPerson.insert(p);

    // Iterate over heightPerson and print data
    cout << "\nHeight Persons (Height -> Name):" << endl;
    for (const auto& pair : heightPerson) {
        cout << pair.first << " cm -> " << pair.second << endl;
    }



    // Create vector sortVector
    vector<pair<string, int>> sortVector;

    // Add data from personHeight to sortVector
    for (const auto& pair : personHeight) {
        sortVector.push_back(pair);
    }

    // Sort the vector with lambda (anonymous) function (Descending order by height)
    sort(sortVector.begin(), sortVector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    // Iterate over sortVector and print data
    cout << "\nSorted by Height (Descending) (Name -> Height):" << endl;
    for (const auto& pair : sortVector) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
