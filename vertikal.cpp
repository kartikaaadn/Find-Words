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
