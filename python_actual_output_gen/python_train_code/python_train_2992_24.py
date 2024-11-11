n, m, k = map(int, input().split())
army = []
s = 0
for i in range(m+1):
    a = bin(int(input()))
    length = len(a)
    a = a[:2] + (2+n-length)*'0' + a[2:]
    army.append(a)
for i in range(m):
    diff = 0
    for j in range(n):
        if army[i][j] != army[m][j]:
            diff += 1
    if diff < k:
        s += 1
print(s)
