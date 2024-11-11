n, m = map(int, input().split())
k = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
    for j in range(m):
        if (i + j) % 2 == 0:
            print(360360, end = ' ')
        else:
            print(360360 + k[i][j] ** 4, end = ' ')
    print()