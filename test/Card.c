#include <stdio.h>
#include <Card.h>

int main(int argc, char* argv[])
{
	int test_count = 1;
	
	// test 1
	Card card1 = { .suit = SUIT_HEART, .rank = RANK_THREE };
	Card card2 = card1;
	
	if (!(Card_compare(card1, card2) == 0 && Card_compare(card2, card1) == 0 &&
		  Card_equals(card1, card2) && Card_equals(card2, card1)))
	{
		return test_count;
	}
	++test_count;
	
	// test 2
	card1 = Card_create(SUIT_HEART, RANK_THREE);
	card2 = Card_create(SUIT_SPADE, RANK_THREE);
	
	if (!(Card_compare(card1, card2) == -1 && Card_compare(card2, card1) == 1 &&
		  !Card_equals(card1, card2)))
	{
		return test_count;
	}
	++test_count;
	
	// test 3
	card1 = Card_create(SUIT_HEART, RANK_THREE);
	card2 = Card_create(SUIT_SPADE, RANK_THREE);
	
	if (!(Card_calcValue(card1) == 6 && Card_calcValue(card2) == 7))
	{
		return test_count;
	}
	++test_count;
	
	// test 4
	Rank some_rank1 = RANK_TWO;
	Rank some_rank2 = RANK_SIX;
	if (!(Rank_predecr(&some_rank1) == RANK_ACE && some_rank1 == RANK_ACE) ||
		!(Rank_predecr(&some_rank2) == RANK_FIVE && some_rank2 == RANK_FIVE))
	{
		return test_count;
	}
	++test_count;
	
	// test 5
	some_rank1 = RANK_TWO;
	some_rank2 = RANK_SIX;
	if (!(Rank_postdecr(&some_rank1) == RANK_TWO && some_rank1 == RANK_ACE) ||
		!(Rank_postdecr(&some_rank2) == RANK_SIX && some_rank2 == RANK_FIVE))
	{
		return test_count;
	}
	++test_count;
	
	// test 6
	some_rank1 = RANK_ACE;
	some_rank2 = RANK_SIX;
	if (!(Rank_preincr(&some_rank1) == RANK_TWO && some_rank1 == RANK_TWO) ||
		!(Rank_preincr(&some_rank2) == RANK_SEVEN && some_rank2 == RANK_SEVEN))
	{
		return test_count;
	}
	++test_count;
	
	// test 7
	some_rank1 = RANK_ACE;
	some_rank2 = RANK_SIX;
	if (!(Rank_postincr(&some_rank1) == RANK_ACE && some_rank1 == RANK_TWO) ||
		!(Rank_postincr(&some_rank2) == RANK_SIX && some_rank2 == RANK_SEVEN))
	{
		return test_count;
	}
	++test_count;
	
	return 0;
}