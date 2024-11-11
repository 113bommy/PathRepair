def diagonal(a):
    global n, m
    max_col = n
    max_row = m
    fdiag = [[] for i in range(max_col + max_row - 1)]
    for y in range(max_col):
        for x in range(max_row):
            fdiag[x+y].append(a[y][x])
    return fdiag



n, m = map(int, input().split())
a = []
b = []
for i in range(n):
    temp = list(map(int, input().split()))
    a.append(temp)

for i in range(n):
    temp = list(map(int, input().split()))
    b.append(temp)

ans_a = diagonal(a)
ans_b = diagonal(b)

for i in range(n + m - 1):
    if set(ans_a[i]) != set(ans_b[i]):
        print('NO')
        exit()

print('YES')
