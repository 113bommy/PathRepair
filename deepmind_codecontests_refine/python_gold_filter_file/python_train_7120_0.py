n = int(input())
inp = [input() for i in range(n)]
A = [[0 for j in range(n)] for i in range(n)]
for i in range(n):
    for j in range(n):
        if inp[i][j] == 'E':
            A[i][j] = 1
k = 0
for i in A:
    if sum(i) == n:
        k += 1
c = 0
for j in range(n):
    s = 0
    for i in range(n):
        s += A[i][j]
    if s == n:
        c += 1

if k > 0 and c > 0:
    print(-1)
    exit(0)

if c > 0:
    for i in range(n):
        for j in range(n):
            if A[i][j] == 0:
                print(i + 1, j + 1)
                break
else:
    for j in range(n):
        for i in range(n):
            if A[i][j] == 0:
                print(i + 1, j + 1)
                break   