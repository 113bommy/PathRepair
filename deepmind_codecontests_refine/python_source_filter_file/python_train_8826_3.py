import sys
input = sys.stdin.readline

#input
N = int(input())
A = list(map(int, input().split()))

#output
from collections import Counter
import bisect

l = Counter(A).most_common()
l = [b for a, b in l]
M = len(l)
l.sort()
p = sum(l)

maximum_operation = [0] * N

ll = []
for x in reversed(range(1, N+1)):
    a = bisect.bisect_left(l, x)
    if a == 0:
        b = M*x
        c = 0
    elif a >= M:
        b = 0
        c = p
    else:
        b = (M-a)*x
        c = sum(l[0:a-1]) 
    ll.append((b + c)/x)

for K in range(M):
    maximum_operation[K] = N - bisect.bisect_left(ll, K+1)

for m in maximum_operation:
    print(m)