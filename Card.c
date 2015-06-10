#include <Card.h>

const unsigned int CARD_NUM_RANKS = 13;
const unsigned int CARD_NUM_SUITS = 4;

Card Card_create(Suit suit, Rank rank)
{
	Card output = { .suit = suit, .rank = rank };
	return output;
}

Rank Rank_predecr(Rank* rank)
{
	if (*rank == RANK_TWO)
	{
		*rank = RANK_ACE;
	}
	else
	{
		--(*rank);
	}
	
	return *rank;
}

Rank Rank_postdecr(Rank* rank)
{
	Rank copy = *rank;
	
	if (*rank == RANK_TWO)
	{
		*rank = RANK_ACE;
	}
	else
	{
		--(*rank);
	}
	
	return copy;
}

Rank Rank_preincr(Rank* rank)
{
	if (*rank == RANK_ACE)
	{
		*rank = RANK_TWO;
	}
	else
	{
		++(*rank);
	}
	
	return *rank;
}

Rank Rank_postincr(Rank* rank)
{
	Rank copy = *rank;
	
	if (*rank == RANK_ACE)
	{
		*rank = RANK_TWO;
	}
	else
	{
		++(*rank);
	}
	
	return copy;
}


bool Card_equals(const Card card1, const Card card2)
{
	return card1.rank == card2.rank && card1.suit == card2.suit;
}

int Card_compare(const Card card1, const Card card2)
{
	if (Card_equals(card1, card2))
	{
		return 0;
	}
	else if (Card_calcValue(card1) > Card_calcValue(card2))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

unsigned int Card_calcValue(const Card card)
{
	return (int)card.rank * CARD_NUM_SUITS + (int)card.suit;
}