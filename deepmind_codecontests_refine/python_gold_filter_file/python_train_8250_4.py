from sys import stdin
input = lambda: stdin.readline().rstrip("\r\n")
from collections import deque as que, defaultdict as vector
from heapq import*
inin = lambda: int(input())
inar = lambda: list(map(int,input().split()))
'''from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack: return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack: break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc'''


Testcase=inin()
for _ in range(Testcase):
    n=inin()
    a=list(input())
    b=list(input())
    a=[int(x) for x in a]+[0]
    b=[int(x) for x in b]+[0]
    aw=[]
    bw=[]
    for i in range(n):
        if a[i]!=a[i+1]:
            aw.append(i+1)
        if b[i]!=b[i+1]:
            bw.append(i+1)
    print(len(aw)+len(bw),*(aw),*bw[::-1])
