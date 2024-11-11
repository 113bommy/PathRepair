import math
n, m = map(int, input().split())
x = list(map(int, input().split()))
p = list(map(int, input().split()))

diff = []
for i in range(n-1):
    diff.append(x[i+1]-x[i])
gcd = diff[0]
for i in range(n-2):
    gcd = math.gcd(diff[i], diff[i+1])

ans = 0
for i in range(m):
    if gcd % p[i] == 0:
        ans = i+1
        break
if ans == 0:
    print("NO")
else:
    print("YES")
    print(x[0], ans)
