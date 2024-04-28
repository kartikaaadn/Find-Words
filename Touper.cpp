//Fungsi ini mengubah setiap huruf kecil dalam string menjadi huruf besar dan mengembalikan string yang telah dimodifikasi.
string toUpperCase(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A'; 
        }
    } return str;
}
