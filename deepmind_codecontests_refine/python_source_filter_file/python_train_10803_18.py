from collections import defaultdict
import math
N = int(input())
ps = defaultdict(int)
for i in range(2, int(math.sqrt(N))+1):
    while N % i == 0:  
        ps[i] += 1
        N //= i
    i += 1
if N > 1:
    ps[N] += 1
ans = 0
for p in ps:
    k = 1
    while ps[p] >= k:
        ans += 1
        ps[p] -= 1
        k += 1
print(ans)