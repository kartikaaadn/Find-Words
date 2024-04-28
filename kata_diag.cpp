// mencari kata secara diagonal

bool findDiagonalWord(char matrix[NUM_ROWS][NUM_COLS], const string& word) {
    // Mencari diagonal kiri atas ke kanan bawah
    for (int x = 0; x <= NUM_ROWS - word.length(); ++x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            int z;
            for (z = 0; z < word.length(); ++z) {
                if (matrix[x + z][y + z] != word[z]) {
                    break;
                }
            }
            if (z == word.length()) return true;
        }
    }

    // Mencari diagonal kanan atas ke kiri bawah
    for (int x = 0; x <= NUM_ROWS - word.length(); ++x) {
        for (int y = NUM_COLS - 1; y >= word.length() - 1; --y) {
            int z;
            for (z = 0; z < word.length(); ++z) {
                if (matrix[x + z][y - z] != word[z]) {
                    break;
                }
            }
            if (z == word.length()) return true;
        }
    }
    
    // Mencari diagonal kiri bawah ke kanan atas
    for (int x = NUM_ROWS - 1; x >= word.length() - 1; --x) {
        for (int y = 0; y <= NUM_COLS - word.length(); ++y) {
            int z;
            for (z = 0; z < word.length(); ++z) {
                if (matrix[x - z][y + z] != word[z]) {
                    break;
                }
            }
            if (z == word.length()) return true;
        }
    }

    // Mencari diagonal kanan bawah ke kiri atas
    for (int x = NUM_ROWS - 1; x >= word.length() - 1; --x) {
        for (int y = NUM_COLS - 1; y >= word.length() - 1; --y) {
            int z;
            for (z = 0; z < word.length(); ++z) {
                if (matrix[x - z][y - z] != word[z]) {
                    break;
                }
            }
            if (z == word.length()) return true;
        }
    }return false;
}
