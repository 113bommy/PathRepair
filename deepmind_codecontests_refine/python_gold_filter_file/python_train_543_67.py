for case in range(int(input())):
    square_target = int(input())
    moves = 0
    current_square = 1
    while current_square != square_target:
        current_square += 2
        moves += ((current_square - 1)/2) * (current_square ** 2 - (current_square - 2) ** 2)
    print(int(moves))


