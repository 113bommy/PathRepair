n = int(input())


def main():
    count = 0
    t_cells = []

# input portion
    for _ in range(n):
        cell = str(input())
        t_cells.append(list(cell))
        # print(t_cells)

# number of adjacent 'c's in a row
    for j in range (0, n):
        pair = 0
        pair_1 = 0
        for i in range (0,n):
            if t_cells[j][i] == 'c':
                pair +=1

# number of adjacent 'c's in a column
            if t_cells[i][j] == 'c':
                pair_1 +=1

        count += pair*(pair-1)/2 + pair_1*(pair_1-1)/2
    print (int(count))


main()