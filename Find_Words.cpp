#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk transform
using namespace std;

const int NUM_ROWS = 24;
const int NUM_COLS = 24;

char matrix[NUM_ROWS][NUM_COLS] = {
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

bool findHorizontalWord(char matrix[NUM_ROWS][NUM_COLS], const string& word) {
    for (int x = 0; x < NUM_ROWS; ++x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x][y + z] != word[z]) {
                    AdaKata= false;
                    break;
                }
            }
            if (AdaKata) return true;
        }
    } return false;
}

bool findVerticalWord(char matrix[NUM_ROWS][NUM_COLS], const string& word) {
    for (int x = 0; x <= NUM_ROWS - word.length(); ++x) {
        for (int y = 0; y < NUM_COLS; ++y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x + z][y] != word[z]) {
                    AdaKata = false;
                    break;
                }
            }
            if (AdaKata) return true;
        }
    }return false;
}

bool findDiagonalWord(char matrix[NUM_ROWS][NUM_COLS], const string& word) {
    // Mencari diagonal kiri atas ke kanan bawah
    for (int x = 0; x <= NUM_ROWS - word.length(); ++x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x + z][y + z] != word[z]) {
                    AdaKata = false;
                    break;
                }
            }
            if (AdaKata) true;
        }
    }

    // Mencari diagonal kanan atas ke kiri bawah
    for (int x = 0; x <= NUM_ROWS - word.length(); ++x) {
        for (int y = NUM_COLS - 1; y >= word.length() - 1; --y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x + z][y - z] != word[z]) {
                    AdaKata = false;
                    break;
                }
            }
            if (AdaKata) return true;
        }
    }

    // Mencari diagonal kiri bawah ke kanan atas
    for (int x = NUM_ROWS - 1; x >= word.length() - 1; --x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x - z][y + z] != word[z]) {
                    AdaKata = false;
                    break;
                }
            }
            if (AdaKata) return true;
        }
    }
    
    // Mencari diagonal kanan bawah ke kiri atas
    for (int x = NUM_ROWS - 1; x >= word.length() - 1; --x) {
        for (int y = NUM_COLS - 1; y >= word.length() - 1; --y) {
            bool AdaKata = true;
            for (int z = 0; z < word.length(); ++z) {
                if (matrix[x - z][y - z] != word[z]) {
                    AdaKata = false;
                    break;
                }
            }
            if (AdaKata) return true;
        }
    } return false;
}

string toUpperCase(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A'; 
        }
    } return str;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    vector<string> kata;
    string kataInput;
    
    for (int x = 0; x < n; ++x) {
        getline(cin, kataInput);
        kata.push_back(kataInput);
    }
    
    for (const string& k : kata) {
        string upperKata = toUpperCase(k);
        bool AdaKata = findHorizontalWord(matrix, upperKata) || findVerticalWord(matrix, upperKata) || findDiagonalWord(matrix, upperKata);
        if (AdaKata) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }   return 0;
}
