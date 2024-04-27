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
