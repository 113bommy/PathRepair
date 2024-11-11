if __name__ == "__main__":
    N, Q = map(int, input().split())
    res = 0
    val = [[0 for j in range(N + 1)] for i in range(3)]
    blocked = [False for j in range(N + 1)]

    for q in range(Q):
        r, c = map(int, input().split())
        val[r][c] ^= 1
        if c > 1:
            res -= blocked[c - 1]
            blocked[c - 1] = False
            blocked[c - 1] = (
                    (val[1][c - 1] == 1 and val[2][c - 1] == 1) or
                    (val[1][c] == 1 and val[2][c] == 1) or
                    (val[1][c - 1] == 1 and val[2][c] == 1) or
                    (val[2][c - 1] == 1 and val[1][c] == 1)
            )
            res += blocked[c - 1]
        if c < N:
            res -= blocked[c]
            blocked[c] = False
            blocked[c] = (
                    (val[1][c] == 1 and val[2][c] == 1) or
                    (val[1][c + 1] == 1 and val[2][c + 1] == 1) or
                    (val[1][c] == 1 and val[2][c + 1] == 1) or
                    (val[2][c] == 1 and val[1][c + 1] == 1)
            )
            res += blocked[c - 1]
        if res > 0:
            print("No")
        else:
            print("Yes")
