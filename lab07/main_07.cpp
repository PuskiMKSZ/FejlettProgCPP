#include <iostream>
#include <vector>

using namespace std;

int main() {


    struct FurcsaABC {
        char abc[256];
      FurcsaABC() {
          char tmp[256];
          for(int i=0 ;i < 256; i++) {
              tmp[i]=i;
          }
          tmp['a']='z';
          tmp['z']='a';
          for (int i=0; i < 256; i++) {
              abc[tmp[i]]=i;
          }
      }

    };


    vector<string> fruits {
    "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    string keresett="berry";

    auto it=find_if(fruits.begin(), fruits.end(),[keresett](const string & item) {
        return item.contains(keresett);
    });
    cout<<"find_if: "<<*it<<endl;
    if (it == fruits.end()) {
        cout<<"not found"<<endl;
    }

    vector<int> t={2,4,6,8};
    auto kettes=all_of(t.begin(), t.end(), [](const int t) {
        return true;
    });



    vector<int> t2 { 1, 2, 3, 4, 5 };

    for_each(t2.begin(), t2.end(), [](int& n) {
        n *= 2;
    });

    cout << "megduplazott elemek: ";
    for_each(t2.begin(), t2.end(), [](int n) { cout << n << " "; });
    cout << endl;


    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
       };
    long long count_5_letters = count_if(months.begin(), months.end(), [](const string& month) {
            return month.length() == 5;
        });

    cout << "ot betubol: " << count_5_letters <<endl<< "\n";


    vector<double> valos { 3, 1, 2, 0, 9 };
    vector<double> v1 = valos;
    sort(v1.begin(), v1.end(), [](double a, double b) {
        return a > b;
    });
    for_each(v1.begin(), v1.end(), [](int v2) {
    cout << v2 << " ";
    });


    vector<pair<string, double>> month_temps {
            {"January", -0.5}, {"February", 1.2}, {"March", 6.8}, {"April", 11.5},
            {"May", 16.3}, {"June", 20.1}, {"July", 22.4}, {"August", 21.8},
            {"September", 17.0}, {"October", 11.2}, {"November", 5.4}, {"December", 0.8}
    };
    sort(month_temps.begin(), month_temps.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });
    cout<<endl;


    cout << "rendezes" << endl;
    for_each(month_temps.begin(), month_temps.end(), [](const auto& p) {
        cout << "  " << p.first << ": " << p.second << " fok" << endl;
    });
    cout << endl;

    vector<double> v3 { 3.1, 1.6, 2.7, 0.91, 9.1 };

    sort(v3.begin(), v3.end(), [](double a, double b) {
    return abs(a) > abs(b);
    });
    for_each(v3.begin(), v3.end(), [](int v4) {
    cout << v4 << " ";
    });

    cout << endl;


    vector<string> months2 {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    FurcsaABC order;

    sort(months2.begin(), months2.end(), [&order](const string& a, const string& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end(),
            [&order](char charA, char charB) {

                return order.abc[(unsigned char)charA] < order.abc[(unsigned char)charB];
            }
        );
    });


    cout << "furcsa abc:" << endl;
    for_each(months2.begin(), months2.end(), [](const string& m) {
        cout << m << " ";
    });














}
