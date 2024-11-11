import sys
from math import sqrt

r = [str(2**i) for i in range(50)]

input = sys.stdin.readline

t = int(input())

while(t>0):
    n = input().strip()
    
    ans = 1<<30
    
    for i in r:
        c = 0
        for j in n:
            if c<len(i) and j==i[c]:
                c+=1
        ans = min(ans, len(i)-c+len(n)-c)
    
    print(ans)
    
    t-=1