import math
n, k = map(int, input().split())
ans = 0
for i in range(n):
    a = max(math.ceil(math.log2(k/(i+1))), 0)
    ans += 0.5**a
print(ans/n)
