for _ in range(int(input())):
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if (A[i][j] ^ i ^ j) & 1:
                A[i][j] += 1
    for a in A:
        print(*a)