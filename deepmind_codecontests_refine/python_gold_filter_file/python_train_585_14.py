import math

k,d,t = map(int,input().split())
n = k // d
if k % d : n += 1
x = (k + n * d) / (2 * t)
cnt = 1 / x
cnt = math.floor(cnt)
rest = 1 - x * cnt
ans = cnt * n * d + rest * t
if(k / t < rest):ans += (rest - k / t) * t
print(ans)