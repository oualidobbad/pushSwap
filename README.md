# pushSwap

## Description
Sorting challenge using two stacks (A/B) and limited operations.

## Features
- Input parsing/validation; small-set and radix/chunk strategies.
- Outputs optimized instruction sequences.

## Technologies Used
- C, Makefile.

## Installation
- Run `make` to build `push_swap`.

## Usage
- `./push_swap "3 2 1"` prints operations to sort stack A.

## Example
- `./push_swap "2 1"` -> `sa`.

## Technical Notes
- Uses two linked-list stacks; operations are constrained to sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr.
- Small input: handcrafted sequences; large input: radix/chunk strategy on indexed values (LSD radix base 2).
- Input parsing validates duplicates, range (int), and numeric tokens; exits with error on invalid data.

## Author
- Oualid Obbad (@oualidobbad)