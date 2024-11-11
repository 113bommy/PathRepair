# Read in the matrix
matrix = []
matrix_rows = 5

for matrix_row in range(matrix_rows):
    matrix.append(input())

# Determine which row the 1 is
one_row = None
for index, rows in enumerate(matrix):
    if '1' in rows:
        one_row = index

# Determine which position the 1 is
one_position = None
for index, numbers in enumerate(matrix[one_row]):
    if '1' in numbers:
        one_position = index

# Determine how many 0 rows there are from top
vertical_movement = None
if one_row == 2:
    vertical_movement = 0
elif one_row == 1 or one_row == 3:
    vertical_movement = 1
else:
    vertical_movement = 2

# Determine how many 0 rows there are from right
horizontal_movement = None
if one_position == 2:
    horizontal_movement = 0
elif one_position == 1 or one_position == 3:
    horizontal_movement = 1
else:
    horizontal_movement = 2

# Output the amount needed for top and right to be 2
amount_of_moves = vertical_movement + horizontal_movement
print(amount_of_moves)