#!/bin/bash

echo " --Running Full push_swap Test with Move Counting-- "

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
for size in 3 4 5; do
    ARG=$(seq 1 $size | tr '\n' ' ')
    test_case "$ARG" "Already Sorted ($size numbers)"
done

### 🚀 Test Reverse Sorted Cases ###
for size in 3 4 5; do
    ARG=$(seq $size -1 1 | tr '\n' ' ')
    test_case "$ARG" "Reverse Sorted ($size numbers)"
done

### 🚀 Test Completely Random Cases ###
for size in 3 4 5; do
    ARG=$(shuf -i 1-100 -n $size | tr '\n' ' ')
    test_case "$ARG" "Random Unsorted ($size numbers)"
done

### 🚀 Test Edge Cases ###
test_case "-2147483648 2147483647 0" "Edge Case (Min & Max INT)"
test_case "1 2 3 4 4" "Duplicate Values (Should Fail)"
test_case "42" "Single Number (Should do nothing)"
test_case "1 2" "Two Sorted Numbers (Should do nothing)"
test_case "2 1" "Two Unsorted Numbers (Should swap once)"

echo "✅ All tests completed!"
