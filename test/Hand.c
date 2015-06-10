#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Hand.h>
#include <Card.h>

int main(int argc, char* argv[])
{
	// setup
	int test_count = 1;
	
	Card card_array[] = { { .suit = SUIT_SPADE, .rank = RANK_FOUR },
						  { .suit = SUIT_CLUB, .rank = RANK_TWO },
						  { .suit = SUIT_HEART, .rank = RANK_TWO },
						  { .suit = SUIT_CLUB, .rank = RANK_ACE },
						  { .suit = SUIT_CLUB, .rank = RANK_THREE } };
	
	Hand hand;
	Hand_init(&hand, card_array);
	
	// test 1
	
	if (!(Card_equals(hand.cards[0], Card_create(SUIT_SPADE, RANK_FOUR)) &&
		  Hand_containsCard(hand, Card_create(SUIT_HEART, RANK_TWO))))
	{
		return test_count;
	}
	++test_count;
	
	// test 2
	
	if (!Card_equals(Hand_getHighCard(hand), Card_create(SUIT_CLUB, RANK_ACE)))
	{
		return test_count;
	}
	++test_count;
	
	// test 3
	
	if (Hand_getType(hand) != HAND_PAIR)
	{
		return test_count;
	}
	++test_count;
	
	// test 4
	
	hand.cards[0] = Card_create(SUIT_SPADE, RANK_FOUR);
	hand.cards[1] = Card_create(SUIT_CLUB, RANK_TWO);
	hand.cards[2] = Card_create(SUIT_HEART, RANK_TWO);
	hand.cards[3] = Card_create(SUIT_CLUB, RANK_ACE);
	hand.cards[4] = Card_create(SUIT_CLUB, RANK_FOUR);
	
	if (Hand_getType(hand) != HAND_TWO_PAIR)
	{
		return test_count;
	}
	++test_count;
	
	// test 5
	
	hand.cards[0] = Card_create(SUIT_SPADE, RANK_FOUR);
	hand.cards[1] = Card_create(SUIT_CLUB, RANK_TWO);
	hand.cards[2] = Card_create(SUIT_HEART, RANK_TWO);
	hand.cards[3] = Card_create(SUIT_CLUB, RANK_TWO);
	hand.cards[4] = Card_create(SUIT_CLUB, RANK_THREE);
	
	if (Hand_getType(hand) != HAND_THREE_KIND)
	{
		return test_count;
	}
	++test_count;
	
	// test 6
	
	hand.cards[0] = Card_create(SUIT_HEART, RANK_ACE);
	hand.cards[1] = Card_create(SUIT_CLUB, RANK_TWO);
	hand.cards[2] = Card_create(SUIT_SPADE, RANK_THREE);
	hand.cards[3] = Card_create(SUIT_CLUB, RANK_FOUR);
	hand.cards[4] = Card_create(SUIT_CLUB, RANK_FIVE);
	
	if (Hand_getType(hand) != HAND_STRAIGHT)
	{
		return test_count;
	}
	++test_count;
	
	// test 7
	
	hand.cards[0] = Card_create(SUIT_DIAMOND, RANK_ACE);
	hand.cards[1] = Card_create(SUIT_DIAMOND, RANK_TWO);
	hand.cards[2] = Card_create(SUIT_DIAMOND, RANK_KING);
	hand.cards[3] = Card_create(SUIT_DIAMOND, RANK_EIGHT);
	hand.cards[4] = Card_create(SUIT_DIAMOND, RANK_FIVE);
	
	if (Hand_getType(hand) != HAND_FLUSH)
	{
		return test_count;
	}
	++test_count;
	
	// test 8
	
	hand.cards[0] = Card_create(SUIT_HEART, RANK_ACE);
	hand.cards[1] = Card_create(SUIT_CLUB, RANK_ACE);
	hand.cards[2] = Card_create(SUIT_SPADE, RANK_ACE);
	hand.cards[3] = Card_create(SUIT_CLUB, RANK_FOUR);
	hand.cards[4] = Card_create(SUIT_CLUB, RANK_FOUR);
	
	if (Hand_getType(hand) != HAND_FULL_HOUSE)
	{
		return test_count;
	}
	++test_count;
	
	// test 9
	
	hand.cards[0] = Card_create(SUIT_HEART, RANK_ACE);
	hand.cards[1] = Card_create(SUIT_CLUB, RANK_ACE);
	hand.cards[2] = Card_create(SUIT_SPADE, RANK_ACE);
	hand.cards[3] = Card_create(SUIT_CLUB, RANK_ACE);
	hand.cards[4] = Card_create(SUIT_CLUB, RANK_FOUR);
	
	if (Hand_getType(hand) != HAND_FOUR_KIND)
	{
		return test_count;
	}
	++test_count;
	
	// test 10
	
	hand.cards[0] = Card_create(SUIT_HEART, RANK_ACE);
	hand.cards[1] = Card_create(SUIT_HEART, RANK_TWO);
	hand.cards[2] = Card_create(SUIT_HEART, RANK_THREE);
	hand.cards[3] = Card_create(SUIT_HEART, RANK_FOUR);
	hand.cards[4] = Card_create(SUIT_HEART, RANK_FIVE);
	
	if (Hand_getType(hand) != HAND_STRAIGHT_FLUSH)
	{
		return test_count;
	}
	++test_count;
	
	return 0;
}