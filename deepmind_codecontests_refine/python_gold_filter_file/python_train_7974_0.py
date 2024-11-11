from math import factorial

def count(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

n, m = map(int, input().split())
table = []
for i in range(n):
    table.append(list(map(int, input().split())))
ans = 0
for i in range(n):
    c0 = table[i].count(0)
    c1 = table[i].count(1)
    for j in range(1, c0 + 1):
        ans += count(c0, j)
    for j in range(1, c1 + 1):
        ans += count(c1, j)
for j in range(m):
    c0 = 0
    c1 = 0
    for i in range(n):
        if table[i][j] == 0:
            c0 += 1
        else:
            c1 += 1
    for i in range(2, c0 + 1):
        ans += count(c0, i)
    for i in range(2, c1 + 1):
        ans += count(c1, i)
print(ans)