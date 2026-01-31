# Procedural Horse Race

**Name:** Steven Houser  
**Course:** CS 121 - Data Structures & Objects  
**Date:** 01/30/26

---

## Program Description

A horse race simulation where 5 horses (numbered 0-4) compete on a 15-character track. Each turn, every horse flips a coin - heads advances 1 space, tails stays put. The race continues until one or more horses cross the finish line.

## Algorithm

**Goal:** Simulate a horse race where 5 horses race on a 15-character track, advancing randomly each turn until a winner is found.

**Variables needed:**
- `horses` - array of 5 integers representing each horse's position (int[5])
- `keepGoing` - controls the main game loop (bool)
- `coin` - random 0 or 1 for coin flip (int)
- `i` - loop counter for iterating through horses (int)

**Constants:**
- `NUM_HORSES` - number of horses in the race (5)
- `TRACK_LENGTH` - length of the track (15)

**Steps:**

1. Set up the program
    - Include necessary libraries (iostream, cstdlib, ctime)
    - Define constants for NUM_HORSES and TRACK_LENGTH
    - Declare function prototypes

2. Initialize the game
    - Seed random number generator with srand(time(NULL))
    - Create horses array with all positions set to 0
    - Set keepGoing to true

3. Main game loop (while keepGoing is true)
    - For each horse (0 to 4):
        - Call advance() to move the horse
        - Call printLane() to display the horse's lane
        - If isWinner() returns true:
            - Set keepGoing to false
    - If no winner yet:
        - Print "Press enter for another turn"
        - Wait for user to press Enter

4. End program

---

## Function Algorithms

### advance(horseNum, horses)

**Goal:** Flip a coin and move the horse forward if heads.

**Steps:**
1. Generate random coin flip (0 or 1)
2. Add coin value to horses[horseNum]
    - If coin is 1 (heads): horse moves forward 1
    - If coin is 0 (tails): horse stays put (adds 0)

### printLane(horseNum, horses)

**Goal:** Display a single horse's lane showing its position on the track.

**Steps:**
1. Get the horse's current position from horses[horseNum]
2. For each position on the track (0 to 14):
    - If current position matches horse's position:
        - Print the horse number
    - Else:
        - Print a dot "."
3. Print a newline

### isWinner(horseNum, horses)

**Goal:** Check if a horse has crossed the finish line.

**Steps:**
1. If horses[horseNum] >= TRACK_LENGTH - 1 (14):
    - Print "Horse [number] WINS!!!"
    - Return true
2. Else:
    - Return false

---

## Blackbelt Extension

Added features in the blackbelt version:
- **Play again loop:** After a race ends, ask the user if they want to race again
- **Custom horse names:** Horses have names instead of just numbers (displayed in winner message)
