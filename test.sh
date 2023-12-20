# Generate 5 random values and store them in the ARG variable
ARG=$(seq 1 5 | shuf | tr '\n' ' ')

echo "$ARG"

# Run push_swap and capture its output in a variable
push_swap_output=$(./push_swap $ARG &)

checker_output=$(echo "$push_swap_output" | ./checker_linux $ARG &)

wait

# Display the output of push_swap
echo "push_swap output:"
echo "$push_swap_output"

echo "checker_linux output:"
echo "$checker_output"

# Count the lines in the output using wc -l
line_count=$(echo "$push_swap_output" | wc -l)

# Display the line count
echo "Line count using wc -l: $((line_count))"

