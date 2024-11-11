import sys
input = sys.stdin.readline

from collections import Counter

l,r=map(int,input().split())

for i in range(l+1,r):
    C=Counter(str(i))
    if max(C.values())==1:
        print(i)
        sys.exit()

print(-1)
