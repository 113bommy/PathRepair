n=int(input())
a,b=map(int,input().split())
p=sorted(list(map(int,input().split())))
print(p)

import bisect
abis = bisect.bisect_right(p,a)
bbis = bisect.bisect_right(p,b)
print(min(abis-0, bbis-abis, len(p)-bbis))
