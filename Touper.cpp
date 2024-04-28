string toUpperCase(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A'; 
        }
    } return str;
}
