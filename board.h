//
//  board.h
//  Solitare
//
//  Created by Martin Garcia on 4/25/17.
//  Copyright © 2017 Martin Garcia. All rights reserved.
//

#ifndef board_h
#define board_h

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

class board
{

private:
    
    struct card
    {
        int value = 0;
        int suite = 0;
        bool king = false;
        bool ace = false;
        bool visible = true;
        card* nextC = NULL;
        card* prevC = NULL;
    };
    card * root = NULL;
    card * tail = NULL;
    card * move = NULL;
    
    
public:
    void initDeck();
    void printDeck();
    void shuffleDeck();
};

void board::initDeck()
{
    //have root
    //need to create 52 cards
    root = new card;
    root->nextC = new card;
    tail = root->nextC;
    
    for (int i = 0; i < 52; i++)
    {
        tail->nextC = new card;
        tail->value = i;
        tail = tail->nextC;
    }
    
    //the cards are now created;
    // load values of the deck;
    
    move = root;
    for (int i = 0; i<52; i++)
    {
        if (i < 13)
        {
            if(i == 0)
            {
                move->ace = true;
            }
            if(i == 12)
            {
                move->king = true;
            }
            int cVal = 0;
            cVal = i+1;
            move->value =cVal;
            move->suite = 1;
    
        }
        else if(i < 26 && i > 12)
        {
            if(i == 13)
            {
                move->ace = true;
            }
            if (i == 25)
            {
                move->king = true;
            }
            int cVal = 0;
            cVal = i - 12;
            move->value =cVal;
            move->suite = 2;
        }
        else if(i > 25 && i < 39)
        {
            if(i == 26)
            {
                move->ace = true;
            }
            if (i == 38) {
                move->king = true;
            }
            int cVal = 0;
            cVal = i - 25;
            move->value =cVal;
            move->suite = 3;
        }
        else
        {
            if (i == 39)
            {
                move->ace = true;
            }
            if (i == 51) {
                move->king = true;
            }
            
            int cVal = 0;
            cVal = i - 38;
            move->value = cVal;
            move->suite = 4;
        }
        
        move = move->nextC;
    }
    
}

void board::printDeck()
{
    move = root;
    
    for (int i = 0; i<52; i++)
    {
        if (move->ace == true )
        {
            cout << "ACE" << endl;
        }
        else if (move->king == true)
        {
            cout << "king" << endl;
        }
        else
        {
            cout << move-> value << endl;
        }
        
        //cout << move-> value << endl;
        move = move->nextC;
    }

}

void board::shuffleDeck()
{
    srand(time(0));
    card * move2 = NULL;

    for(int i = 0; i < 10; i++)
    {
        int val = 0;
        int suite = 0;
        bool ace = false;
        bool king = false;
        int ran1 = rand()%52;
        int rand2 = rand()%52;
    
        move = root;
        move2 = root;
        
        for (int i = 0; i < ran1; i++)
        {
            move = move->nextC;
        }
        for (int i = 0; i < rand2; i++)
        {
            move2 = move2->nextC;
        }
        
        //cout << move->value << " " << move->suite << endl;
        val = move->value;
        suite = move->suite;
        ace = move->ace;
        king = move->king;
        
        move->value = move2->value;
        move->suite = move2->suite;
        move->ace = move2->ace;
        move->king = move2->king;
        
        move2->value = val;
        move2->suite = suite;
        move2->ace = ace;
        move2->king = king;
        
    }
}

#endif /* board_h */
