#pragma once
#include "Songtest.h"

// Definition of the PlayListNode class - *do not change*
class PlayListNode {
public:
    Song song; // data representing a song
    PlayListNode* next; // pointer to the next node in list

    // Constructors
    PlayListNode(Song sng, PlayListNode* nxt) : song(sng), next(nxt) {}
    PlayListNode(Song sng) : song(sng), next(nullptr) {}
};

// Complete class definition here
class PlayList {
public:
    PlayList();
    PlayList(const PlayList& pl);
    ~PlayList();
    PlayList& operator=(const PlayList& pl);

    void insert(Song sng, unsigned int pos);
    Song remove(unsigned int pos);
    void swap(unsigned int pos1, unsigned int pos2);
    Song get(unsigned int pos) const;
    unsigned int size() const;

    void printPlayList() const; // Member function declaration

private:
    PlayListNode* head;
    unsigned int songCount;
};
