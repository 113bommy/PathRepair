n, t = map(int, input().split())
data = [int(i) for i in input().split()]
sums = [0]
for i in range(n):
    sums.append(sums[-1] + data[i])
i, j = 1, 1
ans = 0
while j <= n and i <= n:
    while i <= n and j <= n and sums[j] - sums[i-1] < t:
        j += 1
    ans = max(ans, j-i)
    i += 1
print(ans)
