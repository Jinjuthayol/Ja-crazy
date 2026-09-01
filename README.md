# Hospital Triage Mini Game

A little terminal game written in C++. You play the new hospital manager: patients
walk in one at a time with a symptom, and you decide **which doctor** they should see
and **how urgent** their case is. Match them well to save lives and earn points.

## How to play

Ten patients arrive one by one. For each patient you read their name, age, and
symptom, then type the doctor who fits their specialization and give an urgency level
from 1 to 4. Get both the doctor *and* the urgency right and you score a point. After
each patient, every doctor's chart is printed with their patients sorted by urgency,  
and at the end you find out how many patients you saved.

Urgency levels:

  **1: Fatal** (needs help immediately)\
  **2: Moderate** (needs attention soon)\
  **3: Low** (can wait a bit)\
  **4: Minimal** (routine check-up)

## Build & run

```sh
make        # compiles main.cpp into ./start
make run    # plays the game
```

You just need a C++ compiler (like `g++`).

## What this demonstrates

- **Object-oriented design:** the program is split into small, focused classes: Patient,
  Doctor, Urgency, and the containers that hold them. Each doctor encapsulates its own patient list,
  so the game logic just talks to the classes instead of managing the data directly.
- **Data structures from scratch:** a linked list holds all the doctors, each doctor keeps a second
  linked list of their patients sorted by urgency, and a binary search tree stores the urgency levels
- **Console Interaction:** a typewriter-style text effect and a menu-driven loop read the player's doctor
  and urgency choices, validate the input, and score each correct match.

## Project structure

```
Ja-crazy/
├── main.cpp      # the game loop and story
├── doctor.h      # the Doctor class + the doctor linked list
├── patient.h     # the Patient class
├── urgency.h     # the urgency record
├── bst.h         # the urgency binary search tree
└── makefile      # build/run shortcuts
```
