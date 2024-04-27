#include <iostream>
#include <cstring>
#include <cctype> 
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

void Kapital(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}

bool CariKata(char* word, int startX, int startY, int deltaX, int deltaY) {
    int wordLen = strlen(word);
    for(int i = 0; i < wordLen; i++) {
        int x = startX + i * deltaX;
        int y = startY + i * deltaY;
        if(x < 0 || x >= 24 || y < 0 || y >= 24 || matrix[x][y] != word[i])
            return false;
    }
    return true;
}

bool AdaKata(char* word) {
    int wordLen = strlen(word);
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 24; j++) {
            if(CariKata(word, i, j, 1, 0) ||        // Horizontal
               CariKata(word, i, j, 0, 1) ||        // Vertikal
               CariKata(word, i, j, 1, 1) ||        // Diagonal ke kanan bawah
               CariKata(word, i, j, 1, -1)) {       // Diagonal ke kanan atas
                return true;
            }
        }
    }
    return false;
}

int main() {
    int num;
    cin >> num;
    cin.ignore();

    char words[num][25];

    for(int i = 0; i < num; i++) {
        cin.getline(words[i], 25);
        Kapital(words[i]);
    }

    for(int i = 0; i < num; i++) {
        if(AdaKata(words[i])) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
