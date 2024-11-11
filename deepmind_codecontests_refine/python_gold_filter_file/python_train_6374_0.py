def main():
    n = int(input())
    board = []
    told = []
    blocked = []
    for r in range(1, n + 1):
        endings = list(map(int, input().split()))
        board.append([])
        told.append([])
        for i in range(0, 2 * n, 2):
            x, y = endings[i:i + 2]
            told[-1].append((x, y))
            if x == r and y == i // 2 + 1:
                board[-1].append("X")
                blocked.append((x - 1, y - 1))
            else:
                board[-1].append("")
    unvisited = []
    #print(blocked)
    for bx, by in blocked:
        one_idx = (bx + 1, by + 1)
        if bx and told[bx - 1][by] == one_idx:
            board[bx - 1][by] = "D"
            unvisited.append((bx - 1, by))
        if bx < n - 1 and told[bx + 1][by] == one_idx:
            board[bx + 1][by] = "U"
            unvisited.append((bx + 1, by))
        if by and told[bx][by - 1] == one_idx:
            board[bx][by - 1] = "R"
            unvisited.append((bx, by - 1))
        if by < n - 1 and told[bx][by + 1] == one_idx:
            board[bx][by + 1] = "L"
            unvisited.append((bx, by + 1))
    #print(unvisited)
    z = 0
    while z < len(unvisited):
        x, y = unvisited[z]
        if x and board[x - 1][y] == "" and told[x - 1][y] == told[x][y]:
            unvisited.append((x - 1, y))
            board[x - 1][y] = "D"
        if x < n - 1 and board[x + 1][y] == "" and told[x + 1][y] == told[x][y]:
            unvisited.append((x + 1, y))
            board[x + 1][y] = "U"
        if y and board[x][y - 1] == "" and told[x][y - 1] == told[x][y]:
            unvisited.append((x, y - 1))
            board[x][y - 1] = "R"
        if y < n - 1 and board[x][y + 1] == "" and told[x][y + 1] == told[x][y]:
            unvisited.append((x, y + 1))
            board[x][y + 1] = "L"
        z += 1
    for i in range(n):
        for j in range(n):
            if board[i][j] == "":
                if told[i][j] != (-1, -1):
                    print("INVALID")
                    return
                if i and told[i - 1][j] == (-1, -1):
                    board[i][j] = "U"
                    continue
                if i < n - 1 and told[i + 1][j] == (-1, -1):
                    board[i][j] = "D"
                    continue
                if j and told[i][j - 1] == (-1, -1):
                    board[i][j] = "L"
                    continue
                if j < n - 1 and told[i][j + 1] == (-1, -1):
                    board[i][j] = "R"
                    continue
                print("INVALID")
                return
    print("VALID")
    for k in range(n):
        print("".join(board[k]))
main()