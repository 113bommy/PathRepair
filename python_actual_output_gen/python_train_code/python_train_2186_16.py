N = int(input())

c = [[0] for i in range(10)]

for i in range(1, N+1):
    s = str(i)
    c[int(s[0])][int(s[-1])] += 1

ans = 0

for i in range(10):
    for j in range(10):
        ans += c[i][j] * c[j][i]

print(ans)