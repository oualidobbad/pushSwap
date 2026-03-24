# pushSwap

Sorting challenge using two stacks (A/B) and a constrained instruction set. Focus on minimal move count and correctness across all input sizes.

## Architecture
- Data: singly/doubly linked lists modeling stacks A and B with indexed values for radix operations.
- Ops: implements mandatory moves `sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr` with helpers to apply/log moves.
- Strategies:
  - Tiny (<=5): hard-coded optimal/near-optimal sequences.
  - Large: radix (LSD base 2) or chunked pushes based on index ordering.
- Validation: argv parsing, duplicate detection, int overflow checks; prints `Error` on invalid input.

## Build & Run
- `make` → builds `push_swap` (and usually `checker` if included).
- Run: `./push_swap "3 2 1"` outputs the move list; pipe into `checker` with the same args to verify.

## Technical Notes
- Complexity: radix approach runs in O(n log n) moves over bit length; small-set paths are constant-sized tables.
- Stability: operations mutate linked lists; ensure push/rotate helpers are O(1) and pointer-safe.
- Error handling: fail fast on bad tokens, duplicates, or overflow; free allocated nodes on exit paths.

## Testing Ideas
- Random arrays with `ARG=$(seq 1 100 | shuf)`; verify `./push_swap "$ARG" | ./checker "$ARG"`.
- Edge cases: already sorted, reverse sorted, two/three elements, duplicates (should error).

## Author
Oualid Obbad (@oualidobbad)