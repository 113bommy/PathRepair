import itertools
import bisect

n = int(input())
s = sum(map(int, input().split()))
m = int(input())
b = list(itertools.chain(*(map(int, input().split()) for _ in range(m))))

i = bisect.bisect_left(b, s)
if i == len(b):
    s = -1
elif i % 2 == 0:
    s = b[i]

print(s)
    
