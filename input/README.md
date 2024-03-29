# Daily puzzle descriptions

## Day 1: Calorie Counting 

Santa's reindeer typically eat regular reindeer food, but they need a lot of magical energy to deliver presents on Christmas. For that, their favorite snack is a special type of star fruit that only grows deep in the jungle. The Elves have brought you on their annual expedition to the grove where the fruit grows.

To supply enough magical energy, the expedition needs to retrieve a minimum of fifty stars by December 25th. Although the Elves assure you that the grove has plenty of fruit, you decide to grab any fruit you see along the way, just in case.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

The jungle must be too overgrown and difficult to navigate in vehicles or access from the air; the Elves' expedition traditionally goes on foot. As your boats approach land, the Elves begin taking inventory of their supplies. One important consideration is food - in particular, the number of Calories each Elf is carrying (your puzzle input).

The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, etc. that they've brought with them, one item per line. Each Elf separates their own inventory from the previous Elf's inventory (if any) by a blank line.

For example, suppose the Elves finish writing their items' Calories and end up with the following list:

    1000
    2000
    3000

    4000

    5000
    6000

    7000
    8000
    9000

    10000

This list represents the Calories of the food carried by five Elves:

    The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
    The second Elf is carrying one food item with 4000 Calories.
    The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
    The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
    The fifth Elf is carrying one food item with 10000 Calories.

In case the Elves get hungry and need extra snacks, they need to know which Elf to ask: they'd like to know how many Calories are being carried by the Elf carrying the most Calories. In the example above, this is 24000 (carried by the fourth Elf).

Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?

Your puzzle answer was 69501.

#### Part Two 

By the time you calculate the answer to the Elves' question, they've already realized that the Elf carrying the most Calories of food might eventually run out of snacks.

To avoid this unacceptable situation, the Elves would instead like to know the total Calories carried by the top three Elves carrying the most Calories. That way, even if one of those Elves runs out of snacks, they still have two backups.

In the example above, the top three Elves are the fourth Elf (with 24000 Calories), then the third Elf (with 11000 Calories), then the fifth Elf (with 10000 Calories). The sum of the Calories carried by these three elves is 45000.

Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?

Your puzzle answer was 202346.


## Day 2: Rock Paper Scissors 

The Elves begin to set up camp on the beach. To decide whose tent gets to be closest to the snack storage, a giant Rock Paper Scissors tournament is already in progress.

Rock Paper Scissors is a game between two players. Each game contains many rounds; in each round, the players each simultaneously choose one of Rock, Paper, or Scissors using a hand shape. Then, a winner for that round is selected: Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.

Appreciative of your help yesterday, one Elf gives you an encrypted strategy guide (your puzzle input) that they say will be sure to help you win. "The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors. The second column--" Suddenly, the Elf is called away to help with someone's tent.

The second column, you reason, must be what you should play in response: X for Rock, Y for Paper, and Z for Scissors. Winning every time would be suspicious, so the responses must have been carefully chosen.

The winner of the whole tournament is the player with the highest score. Your total score is the sum of your scores for each round. The score for a single round is the score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).

Since you can't be sure if the Elf is trying to help you or trick you, you should calculate the score you would get if you were to follow the strategy guide.

For example, suppose you were given the following strategy guide:

    A Y
    B X
    C Z

This strategy guide predicts and recommends the following:

    In the first round, your opponent will choose Rock (A), and you should choose Paper (Y). This ends in a win for you with a score of 8 (2 because you chose Paper + 6 because you won).
    In the second round, your opponent will choose Paper (B), and you should choose Rock (X). This ends in a loss for you with a score of 1 (1 + 0).
    The third round is a draw with both players choosing Scissors, giving you a score of 3 + 3 = 6.

In this example, if you were to follow the strategy guide, you would get a total score of 15 (8 + 1 + 6).

What would your total score be if everything goes exactly according to your strategy guide?

Your puzzle answer was 13009.
#### Part Two 

The Elf finishes helping with the tent and sneaks back over to you. "Anyway, the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"

The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. The example above now goes like this:

    In the first round, your opponent will choose Rock (A), and you need the round to end in a draw (Y), so you also choose Rock. This gives you a score of 1 + 3 = 4.
    In the second round, your opponent will choose Paper (B), and you choose Rock so you lose (X) with a score of 1 + 0 = 1.
    In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = 7.

Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of 12.

Following the Elf's instructions for the second column, what would your total score be if everything goes exactly according to your strategy guide?

Your puzzle answer was 10398.


## Day 3: Rucksack Reorganization 

One Elf has the important job of loading all of the rucksacks with supplies for the jungle journey. Unfortunately, that Elf didn't quite follow the packing instructions, and so a few items now need to be rearranged.

Each rucksack has two large compartments. All items of a given type are meant to go into exactly one of the two compartments. The Elf that did the packing failed to follow this rule for exactly one item type per rucksack.

The Elves have made a list of all of the items currently in each rucksack (your puzzle input), but they need your help finding the errors. Every item type is identified by a single lowercase or uppercase letter (that is, a and A refer to different types of items).

The list of items for each rucksack is given as characters all on a single line. A given rucksack always has the same number of items in each of its two compartments, so the first half of the characters represent items in the first compartment, while the second half of the characters represent items in the second compartment.

For example, suppose you have the following list of contents from six rucksacks:

    vJrwpWtwJgWrhcsFMMfFFhFp
    jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
    PmmdzqPrVvPwwTWBwg
    wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
    ttgJtRGJQctTZtZT
    CrZsJsPPZsGzwwsLwLmpwMDw

    The first rucksack contains the items vJrwpWtwJgWrhcsFMMfFFhFp, which means its first compartment contains the items vJrwpWtwJgWr, while the second compartment contains the items hcsFMMfFFhFp. The only item type that appears in both compartments is lowercase p.
    The second rucksack's compartments contain jqHRNqRjqzjGDLGL and rsFMfFZSrLrFZsSL. The only item type that appears in both compartments is uppercase L.
    The third rucksack's compartments contain PmmdzqPrV and vPwwTWBwg; the only common item type is uppercase P.
    The fourth rucksack's compartments only share item type v.
    The fifth rucksack's compartments only share item type t.
    The sixth rucksack's compartments only share item type s.

To help prioritize item rearrangement, every item type can be converted to a priority:

    Lowercase item types a through z have priorities 1 through 26.
    Uppercase item types A through Z have priorities 27 through 52.

In the above example, the priority of the item type that appears in both compartments of each rucksack is 16 (p), 38 (L), 42 (P), 22 (v), 20 (t), and 19 (s); the sum of these is 157.

Find the item type that appears in both compartments of each rucksack. What is the sum of the priorities of those item types?

Your puzzle answer was 7742.
#### Part Two 

As you finish identifying the misplaced items, the Elves come to you with another issue.

For safety, the Elves are divided into groups of three. Every Elf carries a badge that identifies their group. For efficiency, within each group of three Elves, the badge is the only item type carried by all three Elves. That is, if a group's badge is item type B, then all three Elves will have item type B somewhere in their rucksack, and at most two of the Elves will be carrying any other item type.

The problem is that someone forgot to put this year's updated authenticity sticker on the badges. All of the badges need to be pulled out of the rucksacks so the new authenticity stickers can be attached.

Additionally, nobody wrote down which item type corresponds to each group's badges. The only way to tell which item type is the right one is by finding the one item type that is common between all three Elves in each group.

Every set of three lines in your list corresponds to a single group, but each group can have a different badge item type. So, in the above example, the first group's rucksacks are the first three lines:

    vJrwpWtwJgWrhcsFMMfFFhFp
    jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
    PmmdzqPrVvPwwTWBwg

And the second group's rucksacks are the next three lines:

    wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
    ttgJtRGJQctTZtZT
    CrZsJsPPZsGzwwsLwLmpwMDw

In the first group, the only item type that appears in all three rucksacks is lowercase r; this must be their badges. In the second group, their badge item type must be Z.

Priorities for these items must still be found to organize the sticker attachment efforts: here, they are 18 (r) for the first group and 52 (Z) for the second group. The sum of these is 70.

Find the item type that corresponds to the badges of each three-Elf group. What is the sum of the priorities of those item types?

Your puzzle answer was 2276.

## Day 4

Space needs to be cleared before the last supplies can be unloaded from the ships, and so several Elves have been assigned the job of cleaning up sections of the camp. Every section has a unique ID number, and each Elf is assigned a range of section IDs.

However, as some of the Elves compare their section assignments with each other, they've noticed that many of the assignments overlap. To try to quickly find overlaps and reduce duplicated effort, the Elves pair up and make a big list of the section assignments for each pair (your puzzle input).

For example, consider the following list of section assignment pairs:

  2-4,6-8
  2-3,4-5
  5-7,7-9
  2-8,3-7
  6-6,4-6
  2-6,4-8

For the first few pairs, this list means:

    Within the first pair of Elves, the first Elf was assigned sections 2-4 (sections 2, 3, and 4), while the second Elf was assigned sections 6-8 (sections 6, 7, 8).
    The Elves in the second pair were each assigned two sections.
    The Elves in the third pair were each assigned three sections: one got sections 5, 6, and 7, while the other also got 7, plus 8 and 9.

This example list uses single-digit section IDs to make it easier to draw; your actual list might contain larger numbers. Visually, these pairs of section assignments look like this:

  .234.....  2-4
  .....678.  6-8

  .23......  2-3
  ...45....  4-5

  ....567..  5-7
  ......789  7-9

  .2345678.  2-8
  ..34567..  3-7

  .....6...  6-6
  ...456...  4-6

  .23456...  2-6
  ...45678.  4-8

Some of the pairs have noticed that one of their assignments fully contains the other. For example, 2-8 fully contains 3-7, and 6-6 is fully contained by 4-6. In pairs where one assignment fully contains the other, one Elf in the pair would be exclusively cleaning sections their partner will already be cleaning, so these seem like the most in need of reconsideration. In this example, there are 2 such pairs.

In how many assignment pairs does one range fully contain the other?

Your puzzle answer was 431.
#### Part Two

It seems like there is still quite a bit of duplicate work planned. Instead, the Elves would like to know the number of pairs that overlap at all.

In the above example, the first two pairs (2-4,6-8 and 2-3,4-5) don't overlap, while the remaining four pairs (5-7,7-9, 2-8,3-7, 6-6,4-6, and 2-6,4-8) do overlap:

    5-7,7-9 overlaps in a single section, 7.
    2-8,3-7 overlaps all of the sections 3 through 7.
    6-6,4-6 overlaps in a single section, 6.
    2-6,4-8 overlaps in sections 4, 5, and 6.

So, in this example, the number of overlapping assignment pairs is 4.

In how many assignment pairs do the ranges overlap?

Your puzzle answer was 823.

## Day 5

The expedition can depart as soon as the final supplies have been unloaded from the ships. Supplies are stored in stacks of marked crates, but because the needed supplies are buried under many other crates, the crates need to be rearranged.

The ship has a giant cargo crane capable of moving crates between stacks. To ensure none of the crates get crushed or fall over, the crane operator will rearrange them in a series of carefully-planned steps. After the crates are rearranged, the desired crates will be at the top of each stack.

The Elves don't want to interrupt the crane operator during this delicate procedure, but they forgot to ask her which crate will end up where, and they want to be ready to unload them as soon as possible so they can embark.

They do, however, have a drawing of the starting stacks of crates and the rearrangement procedure (your puzzle input). For example:

      [D]    
  [N] [C]    
  [Z] [M] [P]
   1   2   3 

  move 1 from 2 to 1
  move 3 from 1 to 3
  move 2 from 2 to 1
  move 1 from 1 to 2

In this example, there are three stacks of crates. Stack 1 contains two crates: crate Z is on the bottom, and crate N is on top. Stack 2 contains three crates; from bottom to top, they are crates M, C, and D. Finally, stack 3 contains a single crate, P.

Then, the rearrangement procedure is given. In each step of the procedure, a quantity of crates is moved from one stack to a different stack. In the first step of the above rearrangement procedure, one crate is moved from stack 2 to stack 1, resulting in this configuration:

  [D]        
  [N] [C]    
  [Z] [M] [P]
   1   2   3 

In the second step, three crates are moved from stack 1 to stack 3. Crates are moved one at a time, so the first crate to be moved (D) ends up below the second and third crates:

          [Z]
          [N]
      [C] [D]
      [M] [P]
   1   2   3

Then, both crates are moved from stack 2 to stack 1. Again, because crates are moved one at a time, crate C ends up below crate M:

          [Z]
          [N]
  [M]     [D]
  [C]     [P]
   1   2   3

Finally, one crate is moved from stack 1 to stack 2:

          [Z]
          [N]
          [D]
  [C] [M] [P]
   1   2   3

The Elves just need to know which crate will end up on top of each stack; in this example, the top crates are C in stack 1, M in stack 2, and Z in stack 3, so you should combine these together and give the Elves the message CMZ.

After the rearrangement procedure completes, what crate ends up on top of each stack?

Your puzzle answer was RTGWZTHLD.
#### Part Two

As you watch the crane operator expertly rearrange the crates, you notice the process isn't following your prediction.

Some mud was covering the writing on the side of the crane, and you quickly wipe it away. The crane isn't a CrateMover 9000 - it's a CrateMover 9001.

The CrateMover 9001 is notable for many new and exciting features: air conditioning, leather seats, an extra cup holder, and the ability to pick up and move multiple crates at once.

Again considering the example above, the crates begin in the same configuration:

      [D]    
  [N] [C]    
  [Z] [M] [P]
   1   2   3 

Moving a single crate from stack 2 to stack 1 behaves the same as before:

  [D]        
  [N] [C]    
  [Z] [M] [P]
   1   2   3 

However, the action of moving three crates from stack 1 to stack 3 means that those three moved crates stay in the same order, resulting in this new configuration:

          [D]
          [N]
      [C] [Z]
      [M] [P]
   1   2   3

Next, as both crates are moved from stack 2 to stack 1, they retain their order as well:

          [D]
          [N]
  [C]     [Z]
  [M]     [P]
   1   2   3

Finally, a single crate is still moved from stack 1 to stack 2, but now it's crate C that gets moved:

          [D]
          [N]
          [Z]
  [M] [C] [P]
   1   2   3

In this example, the CrateMover 9001 has put the crates in a totally different order: MCD.

Before the rearrangement process finishes, update your simulation so that the Elves know where they should stand to be ready to unload the final supplies. After the rearrangement procedure completes, what crate ends up on top of each stack?

Your puzzle answer was STHGRZZFR.

## Day 6

The preparations are finally complete; you and the Elves leave camp on foot and begin to make your way toward the star fruit grove.

As you move through the dense undergrowth, one of the Elves gives you a handheld device. He says that it has many fancy features, but the most important one to set up right now is the communication system.

However, because he's heard you have significant experience dealing with signal-based systems, he convinced the other Elves that it would be okay to give you their one malfunctioning device - surely you'll have no problem fixing it.

As if inspired by comedic timing, the device emits a few colorful sparks.

To be able to communicate with the Elves, the device needs to lock on to their signal. The signal is a series of seemingly-random characters that the device receives one at a time.

To fix the communication system, you need to add a subroutine to the device that detects a start-of-packet marker in the datastream. In the protocol being used by the Elves, the start of a packet is indicated by a sequence of four characters that are all different.

The device will send your subroutine a datastream buffer (your puzzle input); your subroutine needs to identify the first position where the four most recently received characters were all different. Specifically, it needs to report the number of characters from the beginning of the buffer to the end of the first such four-character marker.

For example, suppose you receive the following datastream buffer:

  mjqjpqmgbljsphdztnvjfqwrcgsmlb

After the first three characters (mjq) have been received, there haven't been enough characters received yet to find the marker. The first time a marker could occur is after the fourth character is received, making the most recent four characters mjqj. Because j is repeated, this isn't a marker.

The first time a marker appears is after the seventh character arrives. Once it does, the last four characters received are jpqm, which are all different. In this case, your subroutine should report the value 7, because the first start-of-packet marker is complete after 7 characters have been processed.

Here are a few more examples:

    bvwbjplbgvbhsrlpgdmjqwftvncz: first marker after character 5
    nppdvjthqldpwncqszvftbrmjlhg: first marker after character 6
    nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg: first marker after character 10
    zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw: first marker after character 11

How many characters need to be processed before the first start-of-packet marker is detected?

Your puzzle answer was 1343.
### Part Two

Your device's communication system is correctly detecting packets, but still isn't working. It looks like it also needs to look for messages.

A start-of-message marker is just like a start-of-packet marker, except it consists of 14 distinct characters rather than 4.

Here are the first positions of start-of-message markers for all of the above examples:

    mjqjpqmgbljsphdztnvjfqwrcgsmlb: first marker after character 19
    bvwbjplbgvbhsrlpgdmjqwftvncz: first marker after character 23
    nppdvjthqldpwncqszvftbrmjlhg: first marker after character 23
    nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg: first marker after character 29
    zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw: first marker after character 26

How many characters need to be processed before the first start-of-message marker is detected?

Your puzzle answer was 2193.

## Day 8

The expedition comes across a peculiar patch of tall trees all planted carefully in a grid. The Elves explain that a previous expedition planted these trees as a reforestation effort. Now, they're curious if this would be a good location for a tree house.

First, determine whether there is enough tree cover here to keep a tree house hidden. To do this, you need to count the number of trees that are visible from outside the grid when looking directly along a row or column.

The Elves have already launched a quadcopter to generate a map with the height of each tree (your puzzle input). For example:

  30373
  25512
  65332
  33549
  35390

Each tree is represented as a single digit whose value is its height, where 0 is the shortest and 9 is the tallest.

A tree is visible if all of the other trees between it and an edge of the grid are shorter than it. Only consider trees in the same row or column; that is, only look up, down, left, or right from any given tree.

All of the trees around the edge of the grid are visible - since they are already on the edge, there are no trees to block the view. In this example, that only leaves the interior nine trees to consider:

    The top-left 5 is visible from the left and top. (It isn't visible from the right or bottom since other trees of height 5 are in the way.)
    The top-middle 5 is visible from the top and right.
    The top-right 1 is not visible from any direction; for it to be visible, there would need to only be trees of height 0 between it and an edge.
    The left-middle 5 is visible, but only from the right.
    The center 3 is not visible from any direction; for it to be visible, there would need to be only trees of at most height 2 between it and an edge.
    The right-middle 3 is visible from the right.
    In the bottom row, the middle 5 is visible, but the 3 and 4 are not.

With 16 trees visible on the edge and another 5 visible in the interior, a total of 21 trees are visible in this arrangement.

Consider your map; how many trees are visible from outside the grid?

Your puzzle answer was 1700.
### Part Two

Content with the amount of tree cover available, the Elves just need to know the best spot to build their tree house: they would like to be able to see a lot of trees.

To measure the viewing distance from a given tree, look up, down, left, and right from that tree; stop if you reach an edge or at the first tree that is the same height or taller than the tree under consideration. (If a tree is right on the edge, at least one of its viewing distances will be zero.)

The Elves don't care about distant trees taller than those found by the rules above; the proposed tree house has large eaves to keep it dry, so they wouldn't be able to see higher than the tree house anyway.

In the example above, consider the middle 5 in the second row:

  30373
  25512
  65332
  33549
  35390

    Looking up, its view is not blocked; it can see 1 tree (of height 3).
    Looking left, its view is blocked immediately; it can see only 1 tree (of height 5, right next to it).
    Looking right, its view is not blocked; it can see 2 trees.
    Looking down, its view is blocked eventually; it can see 2 trees (one of height 3, then the tree of height 5 that blocks its view).

A tree's scenic score is found by multiplying together its viewing distance in each of the four directions. For this tree, this is 4 (found by multiplying 1 * 1 * 2 * 2).

However, you can do even better: consider the tree of height 5 in the middle of the fourth row:

  30373
  25512
  65332
  33549
  35390

    Looking up, its view is blocked at 2 trees (by another tree with a height of 5).
    Looking left, its view is not blocked; it can see 2 trees.
    Looking down, its view is also not blocked; it can see 1 tree.
    Looking right, its view is blocked at 2 trees (by a massive tree of height 9).

This tree's scenic score is 8 (2 * 2 * 1 * 2); this is the ideal spot for the tree house.

Consider each tree on your map. What is the highest scenic score possible for any tree?

Your puzzle answer was 470596.

## Day 9

This rope bridge creaks as you walk along it. You aren't sure how old it is, or whether it can even support your weight.

It seems to support the Elves just fine, though. The bridge spans a gorge which was carved out by the massive river far below you.

You step carefully; as you do, the ropes stretch and twist. You decide to distract yourself by modeling rope physics; maybe you can even figure out where not to step.

Consider a rope with a knot at each end; these knots mark the head and the tail of the rope. If the head moves far enough away from the tail, the tail is pulled toward the head.

Due to nebulous reasoning involving Planck lengths, you should be able to model the positions of the knots on a two-dimensional grid. Then, by following a hypothetical series of motions (your puzzle input) for the head, you can determine how the tail will move.

Due to the aforementioned Planck lengths, the rope must be quite short; in fact, the head (H) and tail (T) must always be touching (diagonally adjacent and even overlapping both count as touching):

  ....
  .TH.
  ....

  ....
  .H..
  ..T.
  ....

  ...
  .H. (H covers T)
  ...

If the head is ever two steps directly up, down, left, or right from the tail, the tail must also move one step in that direction so it remains close enough:

  .....    .....    .....
  .TH.. -> .T.H. -> ..TH.
  .....    .....    .....

  ...    ...    ...
  .T.    .T.    ...
  .H. -> ... -> .T.
  ...    .H.    .H.
  ...    ...    ...

Otherwise, if the head and tail aren't touching and aren't in the same row or column, the tail always moves one step diagonally to keep up:

  .....    .....    .....
  .....    ..H..    ..H..
  ..H.. -> ..... -> ..T..
  .T...    .T...    .....
  .....    .....    .....

  .....    .....    .....
  .....    .....    .....
  ..H.. -> ...H. -> ..TH.
  .T...    .T...    .....
  .....    .....    .....

You just need to work out where the tail goes as the head follows a series of motions. Assume the head and the tail both start at the same position, overlapping.

For example:

  R 4
  U 4
  L 3
  D 1
  R 4
  D 1
  L 5
  R 2

This series of motions moves the head right four steps, then up four steps, then left three steps, then down one step, and so on. After each step, you'll need to update the position of the tail if the step means the head is no longer adjacent to the tail. Visually, these motions occur as follows (s marks the starting position as a reference point):

  == Initial State ==

  ......
  ......
  ......
  ......
  H.....  (H covers T, s)

  == R 4 ==

  ......
  ......
  ......
  ......
  TH....  (T covers s)

  ......
  ......
  ......
  ......
  sTH...

  ......
  ......
  ......
  ......
  s.TH..

  ......
  ......
  ......
  ......
  s..TH.

  == U 4 ==

  ......
  ......
  ......
  ....H.
  s..T..

  ......
  ......
  ....H.
  ....T.
  s.....

  ......
  ....H.
  ....T.
  ......
  s.....

  ....H.
  ....T.
  ......
  ......
  s.....

  == L 3 ==

  ...H..
  ....T.
  ......
  ......
  s.....

  ..HT..
  ......
  ......
  ......
  s.....

  .HT...
  ......
  ......
  ......
  s.....

  == D 1 ==

  ..T...
  .H....
  ......
  ......
  s.....

  == R 4 ==

  ..T...
  ..H...
  ......
  ......
  s.....

  ..T...
  ...H..
  ......
  ......
  s.....

  ......
  ...TH.
  ......
  ......
  s.....

  ......
  ....TH
  ......
  ......
  s.....

  == D 1 ==

  ......
  ....T.
  .....H
  ......
  s.....

  == L 5 ==

  ......
  ....T.
  ....H.
  ......
  s.....

  ......
  ....T.
  ...H..
  ......
  s.....

  ......
  ......
  ..HT..
  ......
  s.....

  ......
  ......
  .HT...
  ......
  s.....

  ......
  ......
  HT....
  ......
  s.....

  == R 2 ==

  ......
  ......
  .H....  (H covers T)
  ......
  s.....

  ......
  ......
  .TH...
  ......
  s.....

After simulating the rope, you can count up all of the positions the tail visited at least once. In this diagram, s again marks the starting position (which the tail also visited) and # marks other positions the tail visited:

  ..##..
  ...##.
  .####.
  ....#.
  s###..

So, there are 13 positions the tail visited at least once.

Simulate your complete hypothetical series of motions. How many positions does the tail of the rope visit at least once?

Your puzzle answer was 6026.
### Part Two

A rope snaps! Suddenly, the river is getting a lot closer than you remember. The bridge is still there, but some of the ropes that broke are now whipping toward you as you fall through the air!

The ropes are moving too quickly to grab; you only have a few seconds to choose how to arch your body to avoid being hit. Fortunately, your simulation can be extended to support longer ropes.

Rather than two knots, you now must simulate a rope consisting of ten knots. One knot is still the head of the rope and moves according to the series of motions. Each knot further down the rope follows the knot in front of it using the same rules as before.

Using the same series of motions as the above example, but with the knots marked H, 1, 2, ..., 9, the motions now occur as follows:

  == Initial State ==

  ......
  ......
  ......
  ......
  H.....  (H covers 1, 2, 3, 4, 5, 6, 7, 8, 9, s)

  == R 4 ==

  ......
  ......
  ......
  ......
  1H....  (1 covers 2, 3, 4, 5, 6, 7, 8, 9, s)

  ......
  ......
  ......
  ......
  21H...  (2 covers 3, 4, 5, 6, 7, 8, 9, s)

  ......
  ......
  ......
  ......
  321H..  (3 covers 4, 5, 6, 7, 8, 9, s)

  ......
  ......
  ......
  ......
  4321H.  (4 covers 5, 6, 7, 8, 9, s)

  == U 4 ==

  ......
  ......
  ......
  ....H.
  4321..  (4 covers 5, 6, 7, 8, 9, s)

  ......
  ......
  ....H.
  .4321.
  5.....  (5 covers 6, 7, 8, 9, s)

  ......
  ....H.
  ....1.
  .432..
  5.....  (5 covers 6, 7, 8, 9, s)

  ....H.
  ....1.
  ..432.
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == L 3 ==

  ...H..
  ....1.
  ..432.
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ..H1..
  ...2..
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  .H1...
  ...2..
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == D 1 ==

  ..1...
  .H.2..
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == R 4 ==

  ..1...
  ..H2..
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ..1...
  ...H..  (H covers 2)
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ...1H.  (1 covers 2)
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ...21H
  ..43..
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == D 1 ==

  ......
  ...21.
  ..43.H
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == L 5 ==

  ......
  ...21.
  ..43H.
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ...21.
  ..4H..  (H covers 3)
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ...2..
  ..H1..  (H covers 4; 1 covers 3)
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ...2..
  .H13..  (1 covers 4)
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ......
  H123..  (2 covers 4)
  .5....
  6.....  (6 covers 7, 8, 9, s)

  == R 2 ==

  ......
  ......
  .H23..  (H covers 1; 2 covers 4)
  .5....
  6.....  (6 covers 7, 8, 9, s)

  ......
  ......
  .1H3..  (H covers 2, 4)
  .5....
  6.....  (6 covers 7, 8, 9, s)

Now, you need to keep track of the positions the new tail, 9, visits. In this example, the tail never moves, and so it only visits 1 position. However, be careful: more types of motion are possible than before, so you might want to visually compare your simulated rope to the one above.

Here's a larger example:

  R 5
  U 8
  L 8
  D 3
  R 17
  D 10
  L 25
  U 20

These motions occur as follows (individual steps are not shown):

== Initial State ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ...........H..............  (H covers 1, 2, 3, 4, 5, 6, 7, 8, 9, s)
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== R 5 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ...........54321H.........  (5 covers 6, 7, 8, 9, s)
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== U 8 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ................H.........
  ................1.........
  ................2.........
  ................3.........
  ...............54.........
  ..............6...........
  .............7............
  ............8.............
  ...........9..............  (9 covers s)
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== L 8 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ........H1234.............
  ............5.............
  ............6.............
  ............7.............
  ............8.............
  ............9.............
  ..........................
  ..........................
  ...........s..............
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== D 3 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  .........2345.............
  ........1...6.............
  ........H...7.............
  ............8.............
  ............9.............
  ..........................
  ..........................
  ...........s..............
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== R 17 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ................987654321H
  ..........................
  ..........................
  ..........................
  ..........................
  ...........s..............
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

== D 10 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ...........s.........98765
  .........................4
  .........................3
  .........................2
  .........................1
  .........................H

== L 25 ==

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ...........s..............
  ..........................
  ..........................
  ..........................
  ..........................
  H123456789................

== U 20 ==

  H.........................
  1.........................
  2.........................
  3.........................
  4.........................
  5.........................
  6.........................
  7.........................
  8.........................
  9.........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ...........s..............
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................

Now, the tail (9) visits 36 positions (including s) at least once:

  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  ..........................
  #.........................
  #.............###.........
  #............#...#........
  .#..........#.....#.......
  ..#..........#.....#......
  ...#........#.......#.....
  ....#......s.........#....
  .....#..............#.....
  ......#............#......
  .......#..........#.......
  ........#........#........
  .........########.........

Simulate your complete series of motions on a larger rope with ten knots. How many positions does the tail of the rope visit at least once?

Your puzzle answer was 2273.

## Day 10

You avoid the ropes, plunge into the river, and swim to shore.

The Elves yell something about meeting back up with them upriver, but the river is too loud to tell exactly what they're saying. They finish crossing the bridge and disappear from view.

Situations like this must be why the Elves prioritized getting the communication system on your handheld device working. You pull it out of your pack, but the amount of water slowly draining from a big crack in its screen tells you it probably won't be of much immediate use.

Unless, that is, you can design a replacement for the device's video system! It seems to be some kind of cathode-ray tube screen and simple CPU that are both driven by a precise clock circuit. The clock circuit ticks at a constant rate; each tick is called a cycle.

Start by figuring out the signal being sent by the CPU. The CPU has a single register, X, which starts with the value 1. It supports only two instructions:

    addx V takes two cycles to complete. After two cycles, the X register is increased by the value V. (V can be negative.)
    noop takes one cycle to complete. It has no other effect.

The CPU uses these instructions in a program (your puzzle input) to, somehow, tell the screen what to draw.

Consider the following small program:

  noop
  addx 3
  addx -5

Execution of this program proceeds as follows:

    At the start of the first cycle, the noop instruction begins execution. During the first cycle, X is 1. After the first cycle, the noop instruction finishes execution, doing nothing.
    At the start of the second cycle, the addx 3 instruction begins execution. During the second cycle, X is still 1.
    During the third cycle, X is still 1. After the third cycle, the addx 3 instruction finishes execution, setting X to 4.
    At the start of the fourth cycle, the addx -5 instruction begins execution. During the fourth cycle, X is still 4.
    During the fifth cycle, X is still 4. After the fifth cycle, the addx -5 instruction finishes execution, setting X to -1.

Maybe you can learn something by looking at the value of the X register throughout execution. For now, consider the signal strength (the cycle number multiplied by the value of the X register) during the 20th cycle and every 40 cycles after that (that is, during the 20th, 60th, 100th, 140th, 180th, and 220th cycles).

For example, consider this larger program:

  addx 15
  addx -11
  addx 6
  addx -3
  addx 5
  addx -1
  addx -8
  addx 13
  addx 4
  noop
  addx -1
  addx 5
  addx -1
  addx 5
  addx -1
  addx 5
  addx -1
  addx 5
  addx -1
  addx -35
  addx 1
  addx 24
  addx -19
  addx 1
  addx 16
  addx -11
  noop
  noop
  addx 21
  addx -15
  noop
  noop
  addx -3
  addx 9
  addx 1
  addx -3
  addx 8
  addx 1
  addx 5
  noop
  noop
  noop
  noop
  noop
  addx -36
  noop
  addx 1
  addx 7
  noop
  noop
  noop
  addx 2
  addx 6
  noop
  noop
  noop
  noop
  noop
  addx 1
  noop
  noop
  addx 7
  addx 1
  noop
  addx -13
  addx 13
  addx 7
  noop
  addx 1
  addx -33
  noop
  noop
  noop
  addx 2
  noop
  noop
  noop
  addx 8
  noop
  addx -1
  addx 2
  addx 1
  noop
  addx 17
  addx -9
  addx 1
  addx 1
  addx -3
  addx 11
  noop
  noop
  addx 1
  noop
  addx 1
  noop
  noop
  addx -13
  addx -19
  addx 1
  addx 3
  addx 26
  addx -30
  addx 12
  addx -1
  addx 3
  addx 1
  noop
  noop
  noop
  addx -9
  addx 18
  addx 1
  addx 2
  noop
  noop
  addx 9
  noop
  noop
  noop
  addx -1
  addx 2
  addx -37
  addx 1
  addx 3
  noop
  addx 15
  addx -21
  addx 22
  addx -6
  addx 1
  noop
  addx 2
  addx 1
  noop
  addx -10
  noop
  noop
  addx 20
  addx 1
  addx 2
  addx 2
  addx -6
  addx -11
  noop
  noop
  noop

The interesting signal strengths can be determined as follows:

    During the 20th cycle, register X has the value 21, so the signal strength is 20 * 21 = 420. (The 20th cycle occurs in the middle of the second addx -1, so the value of register X is the starting value, 1, plus all of the other addx values up to that point: 1 + 15 - 11 + 6 - 3 + 5 - 1 - 8 + 13 + 4 = 21.)
    During the 60th cycle, register X has the value 19, so the signal strength is 60 * 19 = 1140.
    During the 100th cycle, register X has the value 18, so the signal strength is 100 * 18 = 1800.
    During the 140th cycle, register X has the value 21, so the signal strength is 140 * 21 = 2940.
    During the 180th cycle, register X has the value 16, so the signal strength is 180 * 16 = 2880.
    During the 220th cycle, register X has the value 18, so the signal strength is 220 * 18 = 3960.

The sum of these signal strengths is 13140.

Find the signal strength during the 20th, 60th, 100th, 140th, 180th, and 220th cycles. What is the sum of these six signal strengths?

Your puzzle answer was 16480.
### Part Two

It seems like the X register controls the horizontal position of a sprite. Specifically, the sprite is 3 pixels wide, and the X register sets the horizontal position of the middle of that sprite. (In this system, there is no such thing as "vertical position": if the sprite's horizontal position puts its pixels where the CRT is currently drawing, then those pixels will be drawn.)

You count the pixels on the CRT: 40 wide and 6 high. This CRT screen draws the top row of pixels left-to-right, then the row below that, and so on. The left-most pixel in each row is in position 0, and the right-most pixel in each row is in position 39.

Like the CPU, the CRT is tied closely to the clock circuit: the CRT draws a single pixel during each cycle. Representing each pixel of the screen as a #, here are the cycles during which the first and last pixel in each row are drawn:

  Cycle   1 -> ######################################## <- Cycle  40
  Cycle  41 -> ######################################## <- Cycle  80
  Cycle  81 -> ######################################## <- Cycle 120
  Cycle 121 -> ######################################## <- Cycle 160
  Cycle 161 -> ######################################## <- Cycle 200
  Cycle 201 -> ######################################## <- Cycle 240

So, by carefully timing the CPU instructions and the CRT drawing operations, you should be able to determine whether the sprite is visible the instant each pixel is drawn. If the sprite is positioned such that one of its three pixels is the pixel currently being drawn, the screen produces a lit pixel (#); otherwise, the screen leaves the pixel dark (.).

The first few pixels from the larger example above are drawn as follows:

  Sprite position: ###.....................................

  Start cycle   1: begin executing addx 15
  During cycle  1: CRT draws pixel in position 0
  Current CRT row: #

  During cycle  2: CRT draws pixel in position 1
  Current CRT row: ##
  End of cycle  2: finish executing addx 15 (Register X is now 16)
  Sprite position: ...............###......................

  Start cycle   3: begin executing addx -11
  During cycle  3: CRT draws pixel in position 2
  Current CRT row: ##.

  During cycle  4: CRT draws pixel in position 3
  Current CRT row: ##..
  End of cycle  4: finish executing addx -11 (Register X is now 5)
  Sprite position: ....###.................................

  Start cycle   5: begin executing addx 6
  During cycle  5: CRT draws pixel in position 4
  Current CRT row: ##..#

  During cycle  6: CRT draws pixel in position 5
  Current CRT row: ##..##
  End of cycle  6: finish executing addx 6 (Register X is now 11)
  Sprite position: ..........###...........................

  Start cycle   7: begin executing addx -3
  During cycle  7: CRT draws pixel in position 6
  Current CRT row: ##..##.

  During cycle  8: CRT draws pixel in position 7
  Current CRT row: ##..##..
  End of cycle  8: finish executing addx -3 (Register X is now 8)
  Sprite position: .......###..............................

  Start cycle   9: begin executing addx 5
  During cycle  9: CRT draws pixel in position 8
  Current CRT row: ##..##..#

  During cycle 10: CRT draws pixel in position 9
  Current CRT row: ##..##..##
  End of cycle 10: finish executing addx 5 (Register X is now 13)
  Sprite position: ............###.........................

  Start cycle  11: begin executing addx -1
  During cycle 11: CRT draws pixel in position 10
  Current CRT row: ##..##..##.

  During cycle 12: CRT draws pixel in position 11
  Current CRT row: ##..##..##..
  End of cycle 12: finish executing addx -1 (Register X is now 12)
  Sprite position: ...........###..........................

  Start cycle  13: begin executing addx -8
  During cycle 13: CRT draws pixel in position 12
  Current CRT row: ##..##..##..#

  During cycle 14: CRT draws pixel in position 13
  Current CRT row: ##..##..##..##
  End of cycle 14: finish executing addx -8 (Register X is now 4)
  Sprite position: ...###..................................

  Start cycle  15: begin executing addx 13
  During cycle 15: CRT draws pixel in position 14
  Current CRT row: ##..##..##..##.

  During cycle 16: CRT draws pixel in position 15
  Current CRT row: ##..##..##..##..
  End of cycle 16: finish executing addx 13 (Register X is now 17)
  Sprite position: ................###.....................

  Start cycle  17: begin executing addx 4
  During cycle 17: CRT draws pixel in position 16
  Current CRT row: ##..##..##..##..#

  During cycle 18: CRT draws pixel in position 17
  Current CRT row: ##..##..##..##..##
  End of cycle 18: finish executing addx 4 (Register X is now 21)
  Sprite position: ....................###.................

  Start cycle  19: begin executing noop
  During cycle 19: CRT draws pixel in position 18
  Current CRT row: ##..##..##..##..##.
  End of cycle 19: finish executing noop

  Start cycle  20: begin executing addx -1
  During cycle 20: CRT draws pixel in position 19
  Current CRT row: ##..##..##..##..##..

  During cycle 21: CRT draws pixel in position 20
  Current CRT row: ##..##..##..##..##..#
  End of cycle 21: finish executing addx -1 (Register X is now 20)
  Sprite position: ...................###..................

Allowing the program to run to completion causes the CRT to produce the following image:

  ##..##..##..##..##..##..##..##..##..##..
  ###...###...###...###...###...###...###.
  ####....####....####....####....####....
  #####.....#####.....#####.....#####.....
  ######......######......######......####
  #######.......#######.......#######.....

Render the image given by your program. What eight capital letters appear on your CRT?

Your puzzle answer was PLEFULPB.

## Day 14

The distress signal leads you to a giant waterfall! Actually, hang on - the signal seems like it's coming from the waterfall itself, and that doesn't make any sense. However, you do notice a little path that leads behind the waterfall.

Correction: the distress signal leads you behind a giant waterfall! There seems to be a large cave system here, and the signal definitely leads further inside.

As you begin to make your way deeper underground, you feel the ground rumble for a moment. Sand begins pouring into the cave! If you don't quickly figure out where the sand is going, you could quickly become trapped!

Fortunately, your familiarity with analyzing the path of falling material will come in handy here. You scan a two-dimensional vertical slice of the cave above you (your puzzle input) and discover that it is mostly air with structures made of rock.

Your scan traces the path of each solid rock structure and reports the x,y coordinates that form the shape of the path, where x represents distance to the right and y represents distance down. Each path appears as a single line of text in your scan. After the first point of each path, each point indicates the end of a straight horizontal or vertical line to be drawn from the previous point. For example:

  498,4 -> 498,6 -> 496,6
  503,4 -> 502,4 -> 502,9 -> 494,9

This scan means that there are two paths of rock; the first path consists of two straight lines, and the second path consists of three straight lines. (Specifically, the first path consists of a line of rock from 498,4 through 498,6 and another line of rock from 498,6 through 496,6.)

The sand is pouring into the cave from point 500,0.

Drawing rock as #, air as ., and the source of the sand as +, this becomes:


    4     5  5
    9     0  0
    4     0  3
  0 ......+...
  1 ..........
  2 ..........
  3 ..........
  4 ....#...##
  5 ....#...#.
  6 ..###...#.
  7 ........#.
  8 ........#.
  9 #########.

Sand is produced one unit at a time, and the next unit of sand is not produced until the previous unit of sand comes to rest. A unit of sand is large enough to fill one tile of air in your scan.

A unit of sand always falls down one step if possible. If the tile immediately below is blocked (by rock or sand), the unit of sand attempts to instead move diagonally one step down and to the left. If that tile is blocked, the unit of sand attempts to instead move diagonally one step down and to the right. Sand keeps moving as long as it is able to do so, at each step trying to move down, then down-left, then down-right. If all three possible destinations are blocked, the unit of sand comes to rest and no longer moves, at which point the next unit of sand is created back at the source.

So, drawing sand that has come to rest as o, the first unit of sand simply falls straight down and then stops:

  ......+...
  ..........
  ..........
  ..........
  ....#...##
  ....#...#.
  ..###...#.
  ........#.
  ......o.#.
  #########.

The second unit of sand then falls straight down, lands on the first one, and then comes to rest to its left:

  ......+...
  ..........
  ..........
  ..........
  ....#...##
  ....#...#.
  ..###...#.
  ........#.
  .....oo.#.
  #########.

After a total of five units of sand have come to rest, they form this pattern:

  ......+...
  ..........
  ..........
  ..........
  ....#...##
  ....#...#.
  ..###...#.
  ......o.#.
  ....oooo#.
  #########.

After a total of 22 units of sand:

  ......+...
  ..........
  ......o...
  .....ooo..
  ....#ooo##
  ....#ooo#.
  ..###ooo#.
  ....oooo#.
  ...ooooo#.
  #########.

Finally, only two more units of sand can possibly come to rest:

  ......+...
  ..........
  ......o...
  .....ooo..
  ....#ooo##
  ...o#ooo#.
  ..###ooo#.
  ....oooo#.
  .o.ooooo#.
  #########.

Once all 24 units of sand shown above have come to rest, all further sand flows out the bottom, falling into the endless void. Just for fun, the path any new sand takes before falling forever is shown here with ~:

  .......+...
  .......~...
  ......~o...
  .....~ooo..
  ....~#ooo##
  ...~o#ooo#.
  ..~###ooo#.
  ..~..oooo#.
  .~o.ooooo#.
  ~#########.
  ~..........
  ~..........
  ~..........

Using your scan, simulate the falling sand. How many units of sand come to rest before sand starts flowing into the abyss below?

Your puzzle answer was 692.
### Part Two

You realize you misread the scan. There isn't an endless void at the bottom of the scan - there's floor, and you're standing on it!

You don't have time to scan the floor, so assume the floor is an infinite horizontal line with a y coordinate equal to two plus the highest y coordinate of any point in your scan.

In the example above, the highest y coordinate of any point is 9, and so the floor is at y=11. (This is as if your scan contained one extra rock path like -infinity,11 -> infinity,11.) With the added floor, the example above now looks like this:

          ...........+........
          ....................
          ....................
          ....................
          .........#...##.....
          .........#...#......
          .......###...#......
          .............#......
          .............#......
          .....#########......
          ....................
  <-- etc #################### etc -->

To find somewhere safe to stand, you'll need to simulate falling sand until a unit of sand comes to rest at 500,0, blocking the source entirely and stopping the flow of sand into the cave. In the example above, the situation finally looks like this after 93 units of sand come to rest:

  ............o............
  ...........ooo...........
  ..........ooooo..........
  .........ooooooo.........
  ........oo#ooo##o........
  .......ooo#ooo#ooo.......
  ......oo###ooo#oooo......
  .....oooo.oooo#ooooo.....
  ....oooooooooo#oooooo....
  ...ooo#########ooooooo...
  ..ooooo.......ooooooooo..
  #########################

Using your scan, simulate the falling sand until the source of the sand becomes blocked. How many units of sand come to rest?

Your puzzle answer was 31706.

## Day 18

You and the elephants finally reach fresh air. You've emerged near the base of a large volcano that seems to be actively erupting! Fortunately, the lava seems to be flowing away from you and toward the ocean.

Bits of lava are still being ejected toward you, so you're sheltering in the cavern exit a little longer. Outside the cave, you can see the lava landing in a pond and hear it loudly hissing as it solidifies.

Depending on the specific compounds in the lava and speed at which it cools, it might be forming obsidian! The cooling rate should be based on the surface area of the lava droplets, so you take a quick scan of a droplet as it flies past you (your puzzle input).

Because of how quickly the lava is moving, the scan isn't very good; its resolution is quite low and, as a result, it approximates the shape of the lava droplet with 1x1x1 cubes on a 3D grid, each given as its x,y,z position.

To approximate the surface area, count the number of sides of each cube that are not immediately connected to another cube. So, if your scan were only two adjacent cubes like 1,1,1 and 2,1,1, each cube would have a single side covered and five sides exposed, a total surface area of 10 sides.

Here's a larger example:

  2,2,2
  1,2,2
  3,2,2
  2,1,2
  2,3,2
  2,2,1
  2,2,3
  2,2,4
  2,2,6
  1,2,5
  3,2,5
  2,1,5
  2,3,5

In the above example, after counting up all the sides that aren't connected to another cube, the total surface area is 64.

What is the surface area of your scanned lava droplet?

Your puzzle answer was 4300.
### Part Two

Something seems off about your calculation. The cooling rate depends on exterior surface area, but your calculation also included the surface area of air pockets trapped in the lava droplet.

Instead, consider only cube sides that could be reached by the water and steam as the lava droplet tumbles into the pond. The steam will expand to reach as much as possible, completely displacing any air on the outside of the lava droplet but never expanding diagonally.

In the larger example above, exactly one cube of air is trapped within the lava droplet (at 2,2,5), so the exterior surface area of the lava droplet is 58.

What is the exterior surface area of your scanned lava droplet?

Your puzzle answer was 2490.

## Day 21

The monkeys are back! You're worried they're going to try to steal your stuff again, but it seems like they're just holding their ground and making various monkey noises at you.

Eventually, one of the elephants realizes you don't speak monkey and comes over to interpret. As it turns out, they overheard you talking about trying to find the grove; they can show you a shortcut if you answer their riddle.

Each monkey is given a job: either to yell a specific number or to yell the result of a math operation. All of the number-yelling monkeys know their number from the start; however, the math operation monkeys need to wait for two other monkeys to yell a number, and those two other monkeys might also be waiting on other monkeys.

Your job is to work out the number the monkey named root will yell before the monkeys figure it out themselves.

For example:

  root: pppw + sjmn
  dbpl: 5
  cczh: sllz + lgvd
  zczc: 2
  ptdq: humn - dvpt
  dvpt: 3
  lfqf: 4
  humn: 5
  ljgn: 2
  sjmn: drzm * dbpl
  sllz: 4
  pppw: cczh / lfqf
  lgvd: ljgn * ptdq
  drzm: hmdt - zczc
  hmdt: 32

Each line contains the name of a monkey, a colon, and then the job of that monkey:

    A lone number means the monkey's job is simply to yell that number.
    A job like aaaa + bbbb means the monkey waits for monkeys aaaa and bbbb to yell each of their numbers; the monkey then yells the sum of those two numbers.
    aaaa - bbbb means the monkey yells aaaa's number minus bbbb's number.
    Job aaaa * bbbb will yell aaaa's number multiplied by bbbb's number.
    Job aaaa / bbbb will yell aaaa's number divided by bbbb's number.

So, in the above example, monkey drzm has to wait for monkeys hmdt and zczc to yell their numbers. Fortunately, both hmdt and zczc have jobs that involve simply yelling a single number, so they do this immediately: 32 and 2. Monkey drzm can then yell its number by finding 32 minus 2: 30.

Then, monkey sjmn has one of its numbers (30, from monkey drzm), and already has its other number, 5, from dbpl. This allows it to yell its own number by finding 30 multiplied by 5: 150.

This process continues until root yells a number: 152.

However, your actual situation involves considerably more monkeys. What number will the monkey named root yell?

Your puzzle answer was 145167969204648.
--- Part Two ---

Due to some kind of monkey-elephant-human mistranslation, you seem to have misunderstood a few key details about the riddle.

First, you got the wrong job for the monkey named root; specifically, you got the wrong math operation. The correct operation for monkey root should be =, which means that it still listens for two numbers (from the same two monkeys as before), but now checks that the two numbers match.

Second, you got the wrong monkey for the job starting with humn:. It isn't a monkey - it's you. Actually, you got the job wrong, too: you need to figure out what number you need to yell so that root's equality check passes. (The number that appears after humn: in your input is now irrelevant.)

In the above example, the number you need to yell to pass root's equality test is 301. (This causes root to get the same number, 150, from both of its monkeys.)

What number do you yell to pass root's equality test?

Your puzzle answer was 3330805295850.
