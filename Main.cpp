#include <iostream>
#include <vector>
#include <string>
using namespace std;

char matrix[24][24] = {
    "AAFLKHPFSSUFICICLESGNNH",
    "SFVREOMRWLRTTSXOQQNAOAO",
    "QEIAIFXAEIRFVFYSXIMINJI",
    "WSTRLGOCAPBIAFIWIWTUACM",
    "FEYAEAISTPCRLUJKOAKCERS",
    "RVDAKPNDEEHDEMSNCKKFOAH",
    "MRNEDSLCRRIWNRSAAFITMMI",
    "YAAECIEAHYMOTAVHRSSTISB",
    "RJSEWELCCENNIETOHWSGLSE",
    "ATANYYMOIEESNESIOIRELTR",
    "UTENEWEBHMYBETNNRAIEBEN",
    "RCLKUTEAEQJLSGSHTGDSKOA",
    "BHOICATNRRSDDECEHOOLGIT",
    "ENSLUARIRSETALOCOHCTOHE",
    "FZFUDQJYMADOYIWYGLOVESU",
    "TEKALFWONSNAEBMIEJTZNTG",
    "ESWPOSJXEUTUYOZUWAKEZHM",
    "KZUHBPEZEERFLMSNOWBALLH",
    "NSNOWBOARDYTVWYCLEVOHSA",
    "ACOCRQLGZIYCHODRAZZILBI",
    "LBVKKWANZAAQINWOLPWONSL",
    "BFREEZINGRAINSLILGTMELT",
    "HQPYLWHFMNFFUFPSWXNUMMV"
};

bool Horizontal(const string& word, int startX, int startY) {
    int wordLen = word.length();
    for(int i = 0; i < wordLen; i++) {
        int x = startX;
        int y = startY + i;
        if(y < 0 || y >= 24 || toupper(matrix[x][y]) != toupper(word[i]))
            return false;
    }
    return true;
}

bool Vertikal(const string& word, int startX, int startY) {
    int wordLen = word.length();
    for(int i = 0; i < wordLen; i++) {
        int x = startX + i;
        int y = startY;
        if(x < 0 || x >= 24 || toupper(matrix[x][y]) != toupper(word[i]))
            return false;
    }
    return true;
}

bool DiagonalKananBawah(const string& word, int startX, int startY) {
    int wordLen = word.length();
    for(int i = 0; i < wordLen; i++) {
        int x = startX + i;
        int y = startY + i;
        if(x < 0 || x >= 24 || y < 0 || y >= 24 || toupper(matrix[x][y]) != toupper(word[i]))
            return false;
    }
    return true;
}

bool DiagonalKananAtas(const string& word, int startX, int startY) {
    int wordLen = word.length();
    for(int i = 0; i < wordLen; i++) {
        int x = startX - i;
        int y = startY + i;
        if(x < 0 || x >= 24 || y < 0 || y >= 24 || toupper(matrix[x][y]) != toupper(word[i]))
            return false;
    }
    return true;
}

bool AdaKata(const string& word) {
    int wordLen = word.length();
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 24; j++) {
            if(Horizontal(word, i, j) ||            // Horizontal
               Vertikal(word, i, j) ||              // Vertikal
               DiagonalKananBawah(word, i, j) ||    // Diagonal ke kanan bawah
               DiagonalKananAtas(word, i, j)) {     // Diagonal ke kanan atas
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> words;
    string word;
    for(int i = 0; i < n; i++) {
        getline(cin, word); 
        words.push_back(word);
    }

    for(const auto& word : words) {
        if(AdaKata(word)) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
