#!/bin/bash

echo "🔥 Testing All Permutations of 3 Numbers 🔥"

# List all possible 3-number permutations
TEST_CASES=(
    "1 2 3"  # Already sorted
    "1 3 2"
    "2 1 3"
    "2 3 1"
    "3 1 2"
    "3 2 1"  # Reverse sorted
)

# Run each test
for CASE in "${TEST_CASES[@]}"; do
    echo "🔹 Testing: $CASE"
    ./push_swap $CASE | ./checker_linux $CASE
    echo "-------------------"
done

echo "✅ All 3-number cases tested!"
