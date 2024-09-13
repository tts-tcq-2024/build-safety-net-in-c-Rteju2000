#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0',
        '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };

    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }
    return '0';
}

void addSoundexCode(char *soundex, char c, char *prevCode, int *length) {
    char code = getSoundexCode(c);
    if (code != '0' && code != *prevCode) {
        soundex[*length] = code;
        *prevCode = code;
        (*length)++;
    }
}

void addCodes(char *soundex, const char *name) {
    char prevCode = getSoundexCode(name[0]);
    int length = 1;  // Initialize length for the first letter already added

    for (int i = 1; name[i] != '\0' && length < 4; i++) {
        addSoundexCode(soundex, name[i], &prevCode, &length);
    }
}

void generateSoundex(const char *name, char *soundex) {
    if (name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);  // First character is directly copied
    soundex[1] = '\0';              // Ensuring string is properly null-terminated
    addCodes(soundex, name);

    // Pad with zeros to make it 4 characters
    for (int i = strlen(soundex); i < 4; i++) {
        soundex[i] = '0';
    }
    soundex[4] = '\0';  // Ensure null-termination
}

