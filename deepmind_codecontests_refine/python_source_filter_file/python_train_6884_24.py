from sys import stdin
import pprint

input_string = stdin.readline()


index_of_open = 0
index_of_closed = 0
first_double_dots = 0
second_double_dots = 0
num_of_lines = 0


index = 0

while (not index_of_open or not first_double_dots) and index < input_string.__len__():

    if input_string[index] == '[' and not index_of_open:

        index_of_open = index + 1

    elif input_string[index] == ':' and index_of_open:

        first_double_dots = index + 1

    index += 1

index = input_string.__len__() - 1

while (not index_of_closed or not second_double_dots) and index >= 0:

    if input_string[index] == ']' and not index_of_closed:

        index_of_closed = index + 1

    elif input_string[index] == ':' and index_of_closed:

        second_double_dots = index + 1

    index -= 1

# print(index_of_open, first_double_dots, second_double_dots, index_of_closed)

if index_of_closed - index_of_open > 2 and first_double_dots and second_double_dots and not (first_double_dots == second_double_dots):

    for i in range(first_double_dots, second_double_dots):

        if input_string[i] == '|':

            num_of_lines += 1

    print(4 + num_of_lines)

else:
    print(-1)