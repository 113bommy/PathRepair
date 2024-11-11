from sys import stdin,stdout
import math,bisect
from collections import Counter,deque,defaultdict
L=lambda:list(map(int, stdin.readline().strip().split()))
M=lambda:map(int, stdin.readline().strip().split())
I=lambda:int(stdin.readline().strip())
S=lambda:stdin.readline().strip()
C=lambda:stdin.readline().strip().split()
def pr(a):return(" ".join(list(map(str,a))))
#_________________________________________________#


def solve():
    n,w = M()
    a = L()
    r = (w+1)//2
    ans = []
    x = 0
    for i in range(n):
        if a[i] in (r-1,w):
            print(1,i+1,sep="\n")
            break
        elif a[i]<r:
            x+=a[i]
            ans+=[i+1]
            if x>=r:
                print(len(ans),pr(ans),sep="\n")
                break
    else:
        print(-1)
for _ in range(I()):
    solve()
