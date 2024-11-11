from itertools import accumulate
n,w = map(int,input().split())
a = list(map(int,input().split()))
ac = list(accumulate(a))
print(max(min(w + 1 - (max(ac) if max(ac) > 0 else 0) + (min(ac) if min(ac) < 0 else 0),w),0))