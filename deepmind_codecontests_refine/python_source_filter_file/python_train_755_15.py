import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math 
from collections import defaultdict


for _ in range(ri()):
    n=ri()
    l=ria()
    k=max(l)
    if len(set(l))==1:
        wi(-1)
    elif l[0]==k and l[0]!=l[1]:
        wi(1)
    elif l[-1]==k and l[-1]!=l[-2]:
        wi(n)
    else:
        for i in range(1,n-1):
            if l[i]==k and l[i-1]!=k or l[i+1]!=k:
                wi(i+1)
                break
        
