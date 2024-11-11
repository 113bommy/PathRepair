import collections
import math
cnt = collections.Counter()
n = int(input())
a = [int(x) for x in input().split()]
for x in a:
    for i in range(1, int(math.sqrt(x))+1):
        if x%i==0:
            cnt[i] += 1
            if x//i!=i:
                cnt[x//i] += 1
maxi = 0
for x in cnt:
    if x!=1:
        maxi = max(maxi, cnt[x])
print(maxi)
