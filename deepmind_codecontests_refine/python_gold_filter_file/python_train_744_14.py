#start of cp 2.0
#DEAD PERSON CODING
from collections import deque
import sys
def inp():
    return sys.stdin.readline().strip()
for _ in range(int(inp())):
    n=int(inp())
    a=list(map(int,inp().split()))
    p=a.index(1)
    ct=0
    while ct<n:
        if a[p]!=(ct+1):
            break
        ct+=1 
        p=(p+1)%n 
    if ct==n:
        print('YES')
        continue
    p=a.index(1)
    ct=0
    while ct<n:
        if a[p]!=(ct+1):
            break
        ct+=1 
        p=(p-1)%n 
    if ct==n:
        print('YES')
        continue
    print('NO')
    

