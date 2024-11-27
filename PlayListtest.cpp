#include "PlayListtest.h"
#include <iostream>
#include <stdexcept>

using namespace std;

PlayList::PlayList() : head(nullptr), songCount(0) {}

PlayList::PlayList(const PlayList& pl) : head(nullptr), songCount(0) {
    PlayListNode* current = pl.head;
    while (current) {
        insert(current->song, songCount);
        current = current->next;
    }
}

PlayList::~PlayList() {
    while (head) {
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

PlayList& PlayList::operator=(const PlayList& pl) {
    if (this == &pl) {
        return *this;
    }

    while (head) {
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    songCount = 0;

    PlayListNode* current = pl.head;
    while (current) {
        insert(current->song, songCount);
        current = current->next;
    }

    return *this;
}

void PlayList::insert(Song sng, unsigned int pos) {
    if (pos > songCount) {
        cout << "Invalid position" << endl;
    }

    PlayListNode* newNode = new PlayListNode(sng);

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        PlayListNode* prev = head;
        for (unsigned int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    songCount++;
}

Song PlayList::remove(unsigned int pos) {
    if (pos >= songCount) {
    throw std::out_of_range("Invalid position");
}


    PlayListNode* temp = nullptr;
    Song removedSong("Unknown", "Unknown", 1);

    if (pos == 0) {
        temp = head;
        head = head->next;
        removedSong = temp->song;
    } else {
        PlayListNode* prev = head;
        for (unsigned int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        removedSong = temp->song;
    }
    delete temp;
    songCount--;
    return removedSong;
}

void PlayList::swap(unsigned int pos1, unsigned int pos2) {
    if (pos1 >= songCount || pos2 >= songCount || pos1 == pos2) {
        cout << "Invalid positions" << endl;
    }

    PlayListNode* node1 = head;
    PlayListNode* node2 = head;

    for (unsigned int i = 0; i < pos1; ++i) {
        node1 = node1->next;
    }

    for (unsigned int i = 0; i < pos2; ++i) {
        node2 = node2->next;
    }

    Song temp = node1->song;
    node1->song = node2->song;
    node2->song = temp;
}

Song PlayList::get(unsigned int pos) const {
    if (pos >= songCount) {
        cout << "Invalid position" << endl;
    }

    PlayListNode* current = head;
    for (unsigned int i = 0; i < pos; ++i) {
        current = current->next;
    }

    return current->song;
}

unsigned int PlayList::size() const {
    return songCount;
}

void PlayList::printPlayList() const {
    if (size() == 0) {
        cout << "The playlist is empty." << endl;
        return;
    }

    PlayListNode* current = head;
    int position = 1;
    while (current) {
        cout << position << " "
             << current->song.getName() << " ("
             << current->song.getArtist() << ") "
             << current->song.getLength() << "s\n";
        current = current->next;

        if(current == head) {
            cout << "Loop!" << endl;
            break;
        }
        position++;
    }
    cout << "There are " << size() << " songs in the play list.\n";
}
