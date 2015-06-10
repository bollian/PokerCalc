#include <stdio.h>
#include <stdbool.h>
#include <Hand.h>
#include <Card.h>

const unsigned int HAND_NUM_HIGH_CARDS = RANK_ACE - RANK_SIX + 1; // 9
const unsigned int HAND_NUM_PAIRS = 0;
const unsigned int HAND_NUM_TWO_PAIRS = 0;
const unsigned int HAND_NUM_THREE_KINDS = 0;
const unsigned int HAND_NUM_STRAIGHTS = 0;
const unsigned int HAND_NUM_FLUSHES = 0;
const unsigned int HAND_NUM_FULL_HOUSES = 0;
const unsigned int HAND_NUM_FOUR_KINDS;
const unsigned int HAND_NUM_STRAIGHT_FLUSHES = 0;

const unsigned int HAND_SIZE = HAND_SIZE_MACRO;

void Hand_init(Hand* const hand, const Card* const cards)
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		hand->cards[i] = cards[i];
	}
}

unsigned int Hand_calcValue(const Hand hand)
{
	HandType type = Hand_getType(hand);
	unsigned int value = 0;
	
	switch (type)
	{
	case HAND_STRAIGHT_FLUSH:
	case HAND_FOUR_KIND:
		if (type == HAND_FOUR_KIND)
		{
			
		}
		else
		{
			value += HAND_NUM_FOUR_KINDS;
		}
	case HAND_FULL_HOUSE:
		if (type == HAND_FULL_HOUSE)
		{
			
		}
		else
		{
			value += HAND_NUM_FULL_HOUSES;
		}
	case HAND_FLUSH:
		if (type == HAND_FLUSH)
		{
			
		}
		else
		{
			value += HAND_NUM_FLUSHES;
		}
	case HAND_STRAIGHT:
		if (type == HAND_STRAIGHT)
		{
			
		}
		else
		{
			value += HAND_NUM_STRAIGHTS;
		}
	case HAND_THREE_KIND:
		if (type == HAND_THREE_KIND)
		{
			
		}
		else
		{
			value += HAND_NUM_THREE_KINDS;
		}
	case HAND_TWO_PAIR:
		if (type == HAND_TWO_PAIR)
		{
			
		}
		else
		{
			value += HAND_NUM_TWO_PAIRS;
		}
	case HAND_PAIR:
		if (type == HAND_PAIR)
		{
			
		}
		else
		{
			value += HAND_NUM_PAIRS;
		}
	case HAND_HIGH_CARD:
		if (type == HAND_HIGH_CARD)
		{
			
		}
		else
		{
			value += HAND_NUM_HIGH_CARDS;
		}
	}
}

HandType Hand_getType(const Hand hand)
{
	if (Hand_hasStraightFlush(hand))
	{
		return HAND_STRAIGHT_FLUSH;
	}
	else if (Hand_hasFour(hand))
	{
		return HAND_FOUR_KIND;
	}
	else if (Hand_hasFullHouse(hand))
	{
		return HAND_FULL_HOUSE;
	}
	else if (Hand_hasFlush(hand))
	{
		return HAND_FLUSH;
	}
	else if (Hand_hasStraight(hand))
	{
		return HAND_STRAIGHT;
	}
	else if (Hand_hasThree(hand))
	{
		return HAND_THREE_KIND;
	}
	else if (Hand_hasTwoPair(hand))
	{
		return HAND_TWO_PAIR;
	}
	else if (Hand_hasPair(hand))
	{
		return HAND_PAIR;
	}
	else
	{
		return HAND_HIGH_CARD;
	}
}

bool Hand_hasPair(const Hand hand)
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (Hand_countRank(hand, hand.cards[i].rank) == 2)
		{
			return true;
		}
	}

	return false;
}

bool Hand_hasTwoPair(const Hand hand)
{
	const Rank* first_rank = NULL;
	int i;
	
	for (i = 0; i < HAND_SIZE; ++i)
	{
		if (Hand_countRank(hand, hand.cards[i].rank) == 2)
		{
			first_rank = &hand.cards[i].rank;
			break;
		}
	}
	if (first_rank == NULL)
	{
		// no pair was found
		return false;
	}
	
	// no need to start from zero again because of the break statement
	for (Rank rank; i < HAND_SIZE; ++i)
	{
		rank = hand.cards[i].rank;
		if (Hand_countRank(hand, rank) == 2 && rank != *first_rank)
		{
			return true;
		}
	}
	
	// second pair not found
	return false;
}

bool Hand_hasThree(const Hand hand)
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (Hand_countRank(hand, hand.cards[i].rank) == 3)
		{
			return true;
		}
	}

	return false;
}

bool Hand_hasStraight(const Hand hand)
{
	const Rank high_rank = Hand_getHighRank(hand);
	Rank rank = high_rank;
	
	if (rank < RANK_FIVE)
	{
		return false; // straights don't wrap down from ace to king
	}
	
	if (rank == RANK_ACE)
	{
		// look in both directions
		// a straight RANK_ACE - RANK_FIVE will return RANK_ACE as high card
		bool found_straight = false;
		
		Rank_preincr(&rank);
		for (int i = 0; i < HAND_SIZE - 1; ++i, Rank_preincr(&rank))
		{
			// assume until proven otherwise that there is a straight
			found_straight = (Hand_countRank(hand, rank) == 1);
			if (!found_straight)
			{
				// if disproven for any card, stop checking other cards
				break;
			}
		}
		// STATUS: if we've found a straight by ascending up from ace, found_straight will be true
		if (found_straight)
		{
			return true;
		}
		// else search in other direction
		rank = high_rank; // reset state
	}
	
	Rank_predecr(&rank);
	for (int i = 0; i < HAND_SIZE - 1; ++i, Rank_predecr(&rank))
	{
		if (Hand_countRank(hand, rank) != 1)
		{
			// this loop was the last opportunity to find a straight, but it was not found
			return false;
		}
	}
	
	return true;
}

bool Hand_hasFlush(const Hand hand)
{
	Suit last_suit = hand.cards[0].suit;
	
	for (int i = 1; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].suit != last_suit)
		{
			return false;
		}
	}
	
	return true;
}

bool Hand_hasFullHouse(const Hand hand)
{
	// search for pair
	Rank pair_rank;
	bool found_pair = false;
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (Hand_countRank(hand, hand.cards[i].rank) == 2)
		{
			pair_rank = hand.cards[i].rank;
			found_pair = true;
			break; // start searching for the three of a kind
		}
	}
	if (!found_pair)
	{
		return false;
	}
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].rank != pair_rank && 
			Hand_countRank(hand, hand.cards[i].rank) == 3)
		{
			return true;
		}
	}
	
	return false;
}

bool Hand_hasFour(const Hand hand)
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (Hand_countRank(hand, hand.cards[i].rank) == 4)
		{
			return true;
		}
	}
	
	return false;
}

bool Hand_hasStraightFlush(const Hand hand)
{
	return Hand_hasFlush(hand) && Hand_hasStraight(hand);
}

Card Hand_getHighCard(const Hand hand)
{
	int max_indx = 0;
	int max_val = 0;

	for (int i = 0, tmp; i < HAND_SIZE; ++i)
	{
		tmp = Card_calcValue(hand.cards[i]);
		// it is possible to have a card of value 0 at an index besides 0, thus allow 'or equal to'
		if (tmp >= max_val)
		{
			max_val = tmp;
			max_indx = i;
		}
	}

	return hand.cards[max_indx];
}

Rank Hand_getHighRank(const Hand hand)
{
	// two is the lowest rank, ace counts as above king if void of context
	Rank high_rank = RANK_TWO;
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].rank > high_rank)
		{
			high_rank = hand.cards[i].rank;
		}
	}
	
	return high_rank;
}

Suit Hand_getHighSuit(const Hand hand)
{
	// clubs are the lowest ranking suit
	Suit high_suit = SUIT_CLUB;
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].suit > high_suit)
		{
			high_suit = hand.cards[i].suit;
		}
	}
	
	return high_suit;
}


bool Hand_containsCard(const Hand hand, const Card card)
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (Card_equals(hand.cards[i], card))
		{
			return true;
		}
	}

	return false;
}

int Hand_countRank(const Hand hand, const Rank rank)
{
	int count = 0;
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].rank == rank)
		{
			++count;
		}
	}

	return count;
}

int Hand_countSuit(const Hand hand, const Suit suit)
{
	int count = 0;
	
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand.cards[i].suit == suit)
		{
			++count;
		}
	}

	return count;
}

void Hand_setHighCard(Hand hand, const Card new_high)
{

}