#include <iostream>
#include <vector>

struct node {
    int x, y;
    std::string number;
};

void alphabetINIT(std::vector<node> &alphabet) {

    alphabet.push_back({6, 0, "0"});
    alphabet.push_back({2, 1, "1"});
    alphabet.push_back({3, 1, "2"});
    alphabet.push_back({2, 2, "3"});
    alphabet.push_back({4, 0, "4"});
    alphabet.push_back({5, 0, "5"});
    alphabet.push_back({4, 1, "6"});
    alphabet.push_back({});
    alphabet.push_back({7, 0, "8"});

}

void tableINIT(std::vector<std::vector<std::string>> &table) {
    table[2][1] = "1";
    table[3][1] = "2";
    table[2][2] = "3";
    table[4][0] = "4";
    table[5][0] = "5";
    table[4][1] = "6";
    table[7][0] = "8";
}

bool comparator(std::string a, std::string &b) { // a - new, b - old
    if (b == "-1") return true;

    if (a.size() > b.size()) return false;
    if (a.size() < b.size()) return true;
    
    return a < b;
}

void addNumbers(int x, int y, int targetX, int targetY, std::vector<std::vector<std::string>> &table,
                std::vector<node> &alphabet) {

    for (int i = 0; i < alphabet.size(); ++i) {
        if (i == 7) continue;
        std::string newIndex = table[x][y] + alphabet[i].number;
        if (comparator(newIndex, table[x + alphabet[i].x][y + alphabet[i].y])) {
            table[x + alphabet[i].x][y + alphabet[i].y] = newIndex;
        }
    }
//    table[x + 6][y] = table[x][y] + "0";
//    table[x + 2][y + 1] = table[x][y] + "1";
//    table[x + 3][y + 1] = table[x][y] + "2";
//    table[x + 2][y + 2] = table[x][y] + "3";
//    table[x + 4][y] = table[x][y] + "4";
//    table[x + 5][y] = table[x][y] + "5";
//    table[x + 4][y + 1] = table[x][y] + "6";
//    table[x + 7][y] = table[x][y] + "8";
}


int solution() {

    int vertical, angled;

    std::cin >> vertical >> angled;

    std::vector<std::vector<std::string>> table(vertical + 10, std::vector<std::string>(angled + 5, "-1"));

    tableINIT(table);

    std::vector<node> alphabet;

    alphabetINIT(alphabet);

    for (int x = 0; x < vertical + 1; ++x) {
        for (int y = 0; y < angled + 1; ++y) {
            if (table[x][y] == "-1") continue;
            addNumbers(x, y, vertical, angled, table, alphabet);
        }
    }

    if (table[vertical][angled] != "-1") std::cout << table[vertical][angled];
    else std::cout << "Wrong";

    return 0;
}

int main() {

    solution();

    return 0;
}