var = input()
#print(var)
var = list(map(str, var))
#print(var)

seat_col = var[len(var) - 1]
seat_col = str(seat_col)
#print('Seat col: ',seat_col)

var.pop(len(var) - 1)
#print(var)

var = ''.join(var)
var = int(var)
#print(var)

seat_row = var
#print('Seat row: ',seat_row)

t = 0

t = (seat_row - 1) // 4

t = t * (12 + 1)

#print(t)

if seat_row % 2 == 0:
    #print(seat_row % 2)
    t = t + 6 + 1

col_dict = {'a': 4,'b': 5,'c': 6,'d': 3,'e': 2,'f': 1,}

t = t + col_dict[seat_col]

print(t)
