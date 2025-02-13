#!/bin/bash

echo " ---Running Full push_swap Test with Move Counting (100-500 numbers)--- "

### 🚀 Function to Test and Count Moves ###
test_case() {
    ARG="$1"
    DESC="$2"

    echo "🔹 Testing: $DESC"

    # Reset moves.txt to ensure fresh counting for each test
    rm -f moves.txt

    # Run push_swap and count moves
    ./push_swap $ARG | tee moves.txt | ./checker_linux $ARG

    # Get correct move count for this specific test
    MOVE_COUNT=$(wc -l < moves.txt)

    echo "Move count: $MOVE_COUNT"
    echo "-------------------"
}

### 🚀 Test Sorted Cases (Should return 0 moves) ###
for size in 100 250 500; do
    ARG=$(seq 1 $size | tr '\n' ' ')
    test_case "$ARG" "Already Sorted ($size numbers)"
done

### 🚀 Test Reverse Sorted Cases ###
for size in 100 250 500; do
    ARG=$(seq $size -1 1 | tr '\n' ' ')
    test_case "$ARG" "Reverse Sorted ($size numbers)"
done

### 🚀 Test Completely Random Cases ###
for size in 100 250 500; do
    ARG=$(shuf -i 1-10000 -n $size | tr '\n' ' ')
    test_case "$ARG" "Random Unsorted ($size numbers)"
done

echo " All tests completed!"
