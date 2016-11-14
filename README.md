# RaZonogram
Basic command-line Nonogram/Picross game/solver.

<p align="center">![Nonogram example](https://upload.wikimedia.org/wikipedia/commons/d/d0/Nonogram2.jpg)</p>

## The game

A nonogram consists of a two-dimensional grid, filled by tiles which can have 3 different states (empty, filled or denied). Every tile is marked as empty when the grid is loaded.

Each column and row stores an array of 'indices', here called 'clues'; they indicate how many contiguous filled tiles are supposed to exist on the said line. Between each contiguous string of these, there must be *at least* one empty tile.

The objective of the game is to fill the grid according to the clues. To do so, the player has to define the required tiles as filled, which is mandatory for the game to be finished. One can also deny them, so that he knows that no tile should be marked as filled there.

#### Precisions

On the three following examples, the *italic* digits on the left are the clues, the tiles that should be filled are here marked with an '**O**' while the denied ones are marked with an '**X**'.

This line is correct:

| *2* | *2* | ` ` | O | O | X | O | O | X |
|---|---|:---:|---|---|---|---|---|---|

But this one also is:

| *2* | *2* | ` ` | X | O | O | X | O | O |
|---|---|:---:|---|---|---|---|---|---|

As well as this:

| *2* | *2* | ` ` | O | O | X | X | O | O |
|---|---|:---:|---|---|---|---|---|---|

These three examples, while different from each other, have 2 contiguous filled tiles with at least one tile separating them. To know how to put them right, the player has to deduce this from the whole grid.

## Example

Here is an example of a nonogram being solved; filled tiles appear black, while denied ones are crossed.

<p align="center">![Nonogram example](https://upload.wikimedia.org/wikipedia/commons/6/64/Paint_by_numbers_Animation.gif)</p>

## External links

[Link to Wikipedia](https://en.wikipedia.org/wiki/Nonogram) for more information.
