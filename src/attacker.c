// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static direction_t going = DIR_UP, last_going = DIR_STAY;
static position_t last_position = INVALID_POSITION, opponent_position;

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {

  if (going.i != 0 && going.j == 0) {
    printf("to aqui\n");
    if (equal_positions(attacker_position, last_position)) {
      opponent_position = get_spy_position(defender_spy);
      if (last_going.j == 1) {
        going.j = -going.j;
      }
      else
        going = (direction_t)DIR_RIGHT;
    }
  }

  else if (going.j == 1) {
    if (equal_positions(attacker_position, last_position)) {
      going = (direction_t)DIR_UP;
    }
  }

  last_position = attacker_position;
  last_going = going;
  return going;
}

/*----------------------------------------------------------------------------*/
