def main():
    string = input()
    if len(string) % 2 == 1:
        print(-1)
        return
    moves = {"L" :(0, -1), "R": (0, 1), "U" :(0, 1), "D":(0, -1)}
    cor = [0, 0]
    for i in string:
        cor[0] += moves[i][0]
        cor[1] += moves[i][1]
    print((abs(cor[0]) + abs(cor[1])) // 2)


main()