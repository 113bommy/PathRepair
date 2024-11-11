n = int(input())

x = [0, 1] + [0] * (n-1)
for i in range(2, n+1):
    if x[i]: continue
    for j in range(i, n, i):
        if x[j]: continue
        x[j] = j//i

print(*sorted(x)[1:-1])

