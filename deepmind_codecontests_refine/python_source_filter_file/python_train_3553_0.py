n = int(input())
a = [0] + list(map(int, input().split()))
m = int(input())
b = [0] + list(map(int, input().split()))
d = [[0 for j in range(m+1)] for i in range(n+1)]
prev = [0] * (n+1)

for i in range(1, n+1):
    for j in range(1, m+1):
        if a[i] == b[j]:
            d[i][j] = 1
            for k in range(1, i):
                if a[k] < a[i] and d[i][j] < d[k][j] + 1:
                    d[i][j] = d[k][j] + 1
                    prev[i] = k
        else:
            d[i][j] = d[i][j - 1]

pos = 1
for i in range(1, n+1):
    if d[pos][m] < d[i][m]:
        pos = i
ans = []
while pos != 0:
    ans.append(a[pos])
    pos = prev[pos]

print(len(ans))
print(*ans[::-1])

# Thu Oct 10 2019 18:00:25 GMT+0300 (MSK)
