line = input()
n = int(line.split()[0])
m = int(line.split()[1])

# n = 2
# m = 8
# print(n, m)

seats = [ [ None for column in range( 4 ) ] for row in range( n ) ]

def entry_state_transition(col, row):
    if col == 0:
        col = 3
    elif col == 3:
        col = 0
        row += 1
    elif col == 1:
        col = 2
    elif col == 2:
        col = 1
        row += 1

    if row == n:
        row = 0
        col += 1
    return (col, row)

def exit_state_transition(col, row):
    if col == 1:
        col = 0
    elif col == 0:
        col = 2
    elif col == 2:
        col = 3
    elif col == 3:
        col = 1
        row += 1
    return (col, row)

row = 0
col = 0
# print('Passengers are entering')
for i in range(m):
    seats[row][col] = i + 1
    # print(row, col, i + 1)
    col, row = entry_state_transition(col, row)

# print(seats)

# print('Passengers are exiting')
row = 0
col = 1
for i in range(m-1):
    while seats[row][col] is None:
        col, row = exit_state_transition(col, row)
    print(seats[row][col], end=' ')
    col, row = exit_state_transition(col, row)

