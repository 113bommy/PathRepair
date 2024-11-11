n = int(input())
c = [[0 for i in range(10)] for j in range(10)]

for i in range(n):
    x = str(n + 1)
    c[int(x[0])][int(x[-1])] += 1
ans = 0
for i in range(10):
    for j in range(10):
       ans += c[i][j] * c[j][i]
print(ans)