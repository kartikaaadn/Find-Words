bool findHorizontalWord(char matrix[NUM_ROWS][NUM_COLS], const string& word) {
    for (int x = 0; x < NUM_ROWS; ++x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            int z;
            for (z = 0; z < word.length(); ++z) {
                if (matrix[x][y + z] != word[z]) {
                    break;
                }
            }
            if (z == word.length()) return true;
        }
    } return false;
}
