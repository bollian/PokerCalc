#ifndef POKERCALC_HAND_H_
#define POKERCALC_HAND_H_

#include <Card.h>

enum HandType
{
	HAND_HIGH_CARD = 0,
	HAND_PAIR = 1,
	HAND_TWO_PAIR = 2,
	HAND_THREE_KIND = 3,
	HAND_STRAIGHT = 4,
	HAND_FLUSH = 5,
	HAND_FULL_HOUSE = 6,
	HAND_FOUR_KIND = 7,
	HAND_STRAIGHT_FLUSH = 8
};

typedef enum HandType HandType;

extern const unsigned int HAND_NUM_HIGH_CARDS;
extern const unsigned int HAND_NUM_PAIRS;
extern const unsigned int HAND_NUM_TWO_PAIRS;
extern const unsigned int HAND_NUM_THREE_KINDS;
extern const unsigned int HAND_NUM_STRAIGHTS;
extern const unsigned int HAND_NUM_FLUSHES;
extern const unsigned int HAND_NUM_FULL_HOUSES;
extern const unsigned int HAND_NUM_FOUR_KINDS;
extern const unsigned int HAND_NUM_STRAIGHT_FLUSHES;

// change this to change hand size, later undefined
#define HAND_SIZE_MACRO 5

typedef struct Hand
{
	Card cards[HAND_SIZE_MACRO];
} Hand;

extern const unsigned int HAND_SIZE;

void Hand_init(Hand* const, const Card* const);

unsigned int Hand_calcValue(const Hand);

HandType Hand_getType(const Hand);

// hand detection functions in ascending order of value
// each only checks for the existance of its type of hand, not ruling out others
// e.g. a hand can return true for both hasPair and hasFour, even though that's not possible
// as such, to determine the type of hand, call these in descending order of value
// hasTwoPair will not return true on a hand with 4-of-a-kind
bool Hand_hasPair(const Hand);
bool Hand_hasTwoPair(const Hand);
bool Hand_hasThree(const Hand);
bool Hand_hasStraight(const Hand);
bool Hand_hasFlush(const Hand);
bool Hand_hasFullHouse(const Hand);
bool Hand_hasFour(const Hand);
bool Hand_hasStraightFlush(const Hand);
bool Hand_hasRoyalFlush(const Hand);

// hight cards are used to determine draws and no-hands
Card Hand_getHighCard(const Hand);
Rank Hand_getHighRank(const Hand);
Suit Hand_getHighSuit(const Hand);

bool Hand_containsCard(const Hand, const Card);
int Hand_countRank(const Hand, const Rank);
int Hand_countSuit(const Hand, const Suit);

void Hand_setHighCard(Hand, const Card);

#endif // POKERCALC_HAND_H_