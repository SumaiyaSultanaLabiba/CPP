#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    // size_type
    map<int, string>::size_type sz = myMap.size();
    cout << "Size: " << sz << endl;

    // reference
    map<int, string>::reference ref = *myMap.begin();
    cout << "Reference: " << ref.first << " => " << ref.second << endl;

    // const_reference
    map<int, string>::const_reference cref = *myMap.cbegin();
    cout << "Const Reference: " << cref.first << " => " << cref.second << endl;

    // iterator
    map<int, string>::iterator it = myMap.begin();
    cout << "Iterator: " << it->first << " => " << it->second << endl;

    // const_iterator
    map<int, string>::const_iterator cit = myMap.cbegin();
    cout << "Const Iterator: " << cit->first << " => " << cit->second << endl;

    // reverse_iterator
    map<int, string>::reverse_iterator rit = myMap.rbegin();
    cout << "Reverse Iterator: " << rit->first << " => " << rit->second << endl;

    // const_reverse_iterator
    map<int, string>::const_reverse_iterator crit = myMap.crbegin();
    cout << "Const Reverse Iterator: " << crit->first << " => " << crit->second << endl;

    // value_type
    map<int, string>::value_type val = make_pair(4, "Four");
    myMap.insert(val);
    cout << "Value Type Inserted: " << val.first << " => " << val.second << endl;

    // key_type
    map<int, string>::key_type key = 2;
    cout << "Key Type: " << key << endl;

    // key_compare
    map<int, string>::key_compare kcomp = myMap.key_comp();
    cout << "Key Compare (2 < 3): " << kcomp(2, 3) << endl;

    // value_compare
    map<int, string>::value_compare vcomp = myMap.value_comp();
    cout << "Value Compare ((2,Two) < (3,Three)): "
         << vcomp(make_pair(2, "Two"), make_pair(3, "Three")) << endl;

    return 0;
}
