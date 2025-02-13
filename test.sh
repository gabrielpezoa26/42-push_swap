# #!/bin/bash

# echo "🔥 Running Full push_swap Test with Valgrind 🔥"

# rm -f moves.txt  # Ensure fresh file each run

# test_case() {
#     ARG="$1"
#     DESC="$2"

#     echo "🔹 Testing: $DESC"

#     # Export test name for tracking
#     export PUSH_SWAP_TEST_NAME="$DESC"

#     # Run Valgrind on push_swap
#     valgrind --leak-check=full --show-leak-kinds=all \
#              --track-origins=yes --log-file="valgrind_output.txt" \
#              ./push_swap $ARG | sed "s/^/[${DESC}] /" | tee -a moves.txt | ./checker_linux $ARG

#     MOVE_COUNT=$(wc -l < moves.txt)
#     echo "Move count: $MOVE_COUNT"
#     echo "-------------------"
# }

# ### 🚀 Run Tests with Valgrind ###
# test_case "1 2 3" "Already Sorted (3 numbers)"
# test_case "3 2 1" "Reverse Sorted (3 numbers)"
# test_case "$(shuf -i 1-100 -n 3 | tr '\n' ' ')" "Random Unsorted (3 numbers)"
# test_case "$(shuf -i 1-100 -n 5 | tr '\n' ' ')" "Random Unsorted (5 numbers)"

# echo "✅ All tests completed!"
# echo "📜 Check valgrind_output.txt for memory leaks!"






#!/bin/bash

echo "🔥 Running Full push_swap Test with Move Counting 🔥"

### 🛠 Ensure fresh move tracking file ###
rm -f moves.txt

### 🚀 Function to Test and Count Moves ###
test_case() {
    ARG="$1"
    DESC="$2"

    echo "🔹 Testing: $DESC"

    # Export test name so it can be accessed inside push_swap
    export PUSH_SWAP_TEST_NAME="$DESC"

    # Run push_swap, log moves, and run checker
    ./push_swap $ARG | tee -a moves.txt | ./checker_linux $ARG
    MOVE_COUNT=$(wc -l < moves.txt)

    echo "Move count: $MOVE_COUNT"
    echo "-------------------"
}

### 🚀 Test Sorted Cases (Should return 0 moves) ###
for size in 3 5 10 50 100 500; do
    ARG=$(seq 1 $size | tr '\n' ' ')
    test_case "$ARG" "Already Sorted ($size numbers)"
done

### 🚀 Test Reverse Sorted Cases ###
for size in 3 5 10 50 100 500; do
    ARG=$(seq $size -1 1 | tr '\n' ' ')
    test_case "$ARG" "Reverse Sorted ($size numbers)"
done

### 🚀 Test Completely Random Cases ###
for size in 3 5 10 50 100 500; do
    ARG=$(shuf -i 1-10000 -n $size | tr '\n' ' ')
    test_case "$ARG" "Random Unsorted ($size numbers)"
done

### 🚀 Test Edge Cases ###
test_case "-2147483648 2147483647 0" "Edge Case (Min & Max INT)"
test_case "1 2 3 4 4" "Duplicate Values (Should Fail)"
test_case "42" "Single Number (Should do nothing)"
test_case "1 2" "Two Sorted Numbers (Should do nothing)"
test_case "2 1" "Two Unsorted Numbers (Should swap once)"

echo "✅ All tests completed!"
