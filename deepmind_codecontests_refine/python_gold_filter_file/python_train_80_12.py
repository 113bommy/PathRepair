n , m = map(int, input().split())
const = 1000000007
r = [1 for i in range(n+1)]
for i in range(m):
  r[int(input())] = 0
for i in range(2, n+1):
  if r[i] > 0:
    r[i] = (r[i-1] + r[i-2])%const
print(r[n])