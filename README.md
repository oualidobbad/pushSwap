# pushSwap

Sorting integers using only the allowed stack operations on two stacks (A/B) with minimized move count.

## Project Overview
- What it does: reads numbers from argv, validates them, loads them into stack A, and emits the sequence of ops to sort ascending using stack B as auxiliary.
- Real-world analogue: constrained sorting with limited primitives (push/swap/rotate), useful for reasoning about algorithmic costs.
- Problem solved: produce a valid, efficient instruction list under 42’s operation set.

## Architecture & Design
- Data model: singly linked list nodes `t_stack { nb, index, rank, next }` (push_swap.h) for stacks A/B.
- Ops layer: primitives `sa/sb/ss/pa/pb/rotate/rev_rotat` etc. mutate lists in O(1).
- Ranking/indexing: `set_rank()` assigns compressed ranks (1..n) to values; `set_index()` annotates positions for rotation decisions.
- Strategies:
  - Size 2/3: `sa` / `sort_three` specialized sequences.
  - Size <=7: `sort_less_than7()` isolates minima to B, sorts 3, then pushes back.
  - Size >7: `sorting_stack()` chunk/radix-like pass using rank windows and rotations to bucket elements into B, then `move_to_back()` rebuilds A in order.

## Core Concepts (with code)
- Rank compression for stable ordering:
  ```c
  // sort_stack.c
  set_rank(*stack);           // assign rank based on value ordering
  if (ft_last_node(*stack)->rank < i) pb(stack, &b); // bucket small ranks
  ```
- Position-aware rotation: choose rotate vs reverse-rotate based on index to minimize moves.
  ```c
  // sort_less_than7.c
  pos = raje3_position(*a, i);
  if (pos < size/2) rev_rotat(a, &b, 'a');
  else rotate(a, &b, 'a');
  ```
- Chunked pass for larger inputs: window size `shank` controls how many ranks are pushed per sweep (10 for <=100, 30 beyond).

## Code Walkthrough
1) `main` (push_swap.c): split argv, build stack A (`ft_push_nbr` + libft `ft_split`), then `sort_stack` if unsorted.
2) `sort_stack`: selects strategy by size; tiny → direct ops, small → `sort_less_than7`, large → `sorting_stack`.
3) `sorting_stack`: iterates ranks, pushes to B when inside current window, rotates otherwise; grows window (`shank + i`).
4) `move_to_back`: re-inserts from B to A by always pushing the current max rank to restore sorted order.
5) Clean up: `free_stack` releases all nodes.

## Installation & Setup
- `make` in repo root → builds `push_swap` (plus bundled libft/ft_printf).
- Requires: `cc`, `make`, POSIX libc.

## Usage Guide
```bash
./push_swap "3 2 1"
# outputs moves, e.g., sa

ARG="$(seq 1 100 | shuf)"; ./push_swap $ARG | wc -l   # count moves
```
- Use an external `checker` if desired to validate the move list.

## Technical Deep Dive
- Complexity: chunk strategy ~O(n log n) moves over rank window passes; tiny paths are constant-sized tables.
- Data structure: singly linked lists chosen for O(1) push/pop on head; rotations adjust head/tail pointers.
- Safety: rank/index recomputed after mutations before positional decisions; integer parsing should guard overflow (enhancement noted below).

## Improvements & Future Work
- Add robust input validation (duplicate detection, INT overflow) before building stacks.
- Tune chunk size dynamically based on n for fewer moves.
- Add a `checker` implementation and move counter benchmarking.

## Author
Oualid Obbad (@oualidobbad)