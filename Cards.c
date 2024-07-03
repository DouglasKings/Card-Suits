#include <stdio.h>

// Declare ranks here, at the global scope
char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Enumeration for suits
enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

// Structure for cards
struct Card {
    enum Suit suit;
    int rank; // Ranks are integers starting from 1 (Ace) to 13 (King)
};

// Function prototype and declaration
void printCardDetails(struct Card* card);

int main() {
    // Initialize an array of Card structures representing a standard 52-card deck
    struct Card deck[52];
    
    for(int i = 0; i < 52; i++) {
        deck[i].suit = (i / 13) % 4; // Calculate the suit based on the index
        deck[i].rank = i % 13 + 1; // Calculate the rank based on the index
        
        // Assigning the rank name using the ranks array
        printf("Card %d: %s of %s, Value: %d\n", i+1, ranks[deck[i].rank-1], ranks[deck[i].suit], deck[i].rank);
        
        // Uncomment the following line if you want to print the details using the printCardDetails function
        // printCardDetails(&deck[i]);
    }

    return 0;
}

// Implementation of the printCardDetails function
void printCardDetails(struct Card* card) {
    switch(card->suit) {
        case HEARTS:
            printf("%s of Hearts", ranks[card->rank-1]);
            break;
        case DIAMONDS:
            printf("%s of Diamonds", ranks[card->rank-1]);
            break;
        case CLUBS:
            printf("%s of Clubs", ranks[card->rank-1]);
            break;
        case SPADES:
            printf("%s of Spades", ranks[card->rank-1]);
            break;
    }
    printf(", Value: %d\n", card->rank);
}