#include "PlayListtest.h"
#include <iostream>
using namespace std;

void printMenu() {
    cout << "Menu:\n"
         << "1 - Enter a song in the play list at a given position\n"
         << "2 - Remove a song from the play list at a given position\n"
         << "3 - Swap two songs in the play list\n"
         << "4 - Print all the songs in the play list\n"
         << "5 - Quit\n";
}

int main() {
    PlayList playlist;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, artist;
            int length, position;
            cout << "Song name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Artist: ";
            getline(cin, artist);
            cout << "Length: ";
            cin >> length;
            cout << "Position (1 to " << playlist.size() + 1 << "): ";
            cin >> position;

            playlist.insert(Song(name, artist, length), position - 1);
            cout << "You entered " << name << " at position " << position << " in the play list\n";
        } else if (choice == 2) {
            unsigned int position;
            cout << "Position (1 to " << playlist.size() << "): ";
            cin >> position;

            Song removed = playlist.remove(position - 1);
            cout << "You removed " << removed.getName() << " from the play list\n";
        } else if (choice == 3) {
            unsigned int pos1, pos2;
            cout << "Swap song at position (1 to " << playlist.size() << "): ";
            cin >> pos1;
            cout << "with the song at position (1 to " << playlist.size() << "): ";
            cin >> pos2;

            playlist.swap(pos1 - 1, pos2 - 1);
            cout << "You swapped the songs at positions " << pos1 << " and " << pos2 << "\n";
        } else if (choice == 4) {
            playlist.printPlayList();
        }
    } while (choice != 5);

    cout << "You have chosen to quit the program.\n";
    return 0;
}
