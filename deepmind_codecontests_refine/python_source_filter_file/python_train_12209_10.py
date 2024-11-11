import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
def ceil(x, y=1): return int(-(-x // y))
import math 
from collections import defaultdict

for _ in range(ri()):
    n,k=ria()
    l=ria()
    ans=[]
    flag=0
    for i in l:
        if k&1 and i==k/2:
            if flag&1:
                ans.append(1)
            else:
                ans.append(0)
            flag+=1
        elif 2* i<k:
            ans.append(0)
        else:
            ans.append(1)
    wia(ans)
