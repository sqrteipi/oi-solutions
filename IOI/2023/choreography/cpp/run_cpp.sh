#!/bin/bash

problem="choreography"
memory=2097152  # 2GB
stack_size=2097152  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"

input_file="input.txt"
output_file="output.txt"

# Run the compiled program with input redirection and output redirection
"./${problem}" < "${input_file}" > "${output_file}"