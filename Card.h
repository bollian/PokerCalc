#ifndef POKERCALC_CARD_H_
#define POKERCALC_CARD_H_

#include <stdbool.h>

extern const unsigned int CARD_NUM_RANKS;
extern const unsigned int CARD_NUM_SUITS;

enum Suit
{
	SUIT_CLUB = 0,
	SUIT_DIAMOND = 1,
	SUIT_HEART = 2,
	SUIT_SPADE = 3
};

enum Rank
{
	RANK_TWO = 0,
	RANK_THREE = 1,
	RANK_FOUR = 2,
	RANK_FIVE = 3,
	RANK_SIX = 4,
	RANK_SEVEN = 5,
	RANK_EIGHT = 6,
	RANK_NINE = 7,
	RANK_TEN = 8,
	RANK_JACK = 9,
	RANK_QUEEN = 10,
	RANK_KING = 11,
	RANK_ACE = 12
};

typedef enum Rank Rank;
typedef enum Suit Suit;

typedef struct Card
{
	Suit suit;
	Rank rank;
} Card;

Card Card_create(Suit, Rank);

Rank Rank_predecr(Rank*);
Rank Rank_postdecr(Rank*);
Rank Rank_preincr(Rank*);
Rank Rank_postincr(Rank*);

bool Card_equals(const Card, const Card);

// returns returns 1, 0, or -1 based on if the symbol between the 2 should be >, =, or <
int Card_compare(const Card, const Card);

unsigned int Card_calcValue(const Card);

#endif // POKERCALC_CARD_H_