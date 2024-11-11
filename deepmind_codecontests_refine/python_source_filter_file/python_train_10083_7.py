n, a, b = [int(i) for i in input().split()]
X = [int(i) for i in input.split()]

ans = 0
for i in range(n-1):
  ans += min(a * (X[i+1] - X[i]), b)

print(ans)