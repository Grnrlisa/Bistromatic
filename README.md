# Bistromatic
Infinite calculator


The goal of this project is to write a program that will display the result of an evaluated mathematical expression. The expression will be composed of infinite integers that can be expressed in any base.
The program must handle the following operators: +-*/%, parentheses, operation priorities and syntax errors,
but not float numbers.

USAGE :

echo "expression" | ./calc "base" "operators" size_to_echo

echo "3+3" | ./calc "0123456789" "()+-*/%" 3 #should output 6
