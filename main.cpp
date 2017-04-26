//
//  main.cpp
//  Solitare
//
//  Created by Martin Garcia on 4/21/17.
//  Copyright © 2017 Martin Garcia. All rights reserved.
//

#include "board.h"




int main()
{
    board play;
    play.initDeck();
    play.shuffleDeck();
    play.printDeck();
    return 0;
}
