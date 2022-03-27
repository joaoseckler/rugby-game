// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static direction_t going = DIR_UP;
static position_t last_position = INVALID_POSITION, opponent_position;
static int round = 0;

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {

  if (round == 5)
    opponent_position = get_spy_position(attacker_spy);
  round++;

  if (equal_positions(last_position, defender_position)) {
    going.i = -going.i;
  }

  last_position = defender_position;
  return going;
}

/*----------------------------------------------------------------------------*/
