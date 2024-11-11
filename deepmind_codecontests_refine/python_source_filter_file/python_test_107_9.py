from sys import stdin
input = stdin.readline
from collections import deque
T = int(input())

def possible(n,a,b):
    if a+b >n-2:
        return False
    if abs(a-b) >=2:
        return False
    if a <=(n-2)//2 and b <= (n-2)//2+1:
        return True
    if a <=(n-2)//2+1 and b <= (n-2)//2:
        return True
    return True

def li(n,a,b):
    dq = deque([])
    for i in range(1,n+1):
        dq.append(i)
    ret = []
    
    if a == 0 and b == 0:
        return list(range(1,n+1))
    elif a > b:
        ret.append(dq.popleft())
        ret.append(dq.pop())
        for _ in range(b):
            ret.append(dq.popleft())
            ret.append(dq.pop())
        if dq:
            for i in reversed(dq):
                ret.append(i)
    elif a == b:
        ret.append(dq.popleft())
        ret.append(dq.pop())
        for _ in range(a):
            ret.append(dq.popleft())
            ret.append(dq.pop())
        if dq:
            for i in dq:
                ret.append(i)
    else:
        ret.append(dq.pop())
        ret.append(dq.popleft())
        for _ in range(a):
            ret.append(dq.pop())
            ret.append(dq.popleft())
        if dq:
            for i in dq:
                ret.append(i)
    return ret
for _ in range(T):
    n,a,b = map(int,input().split())
    if not possible(n,a,b):
        print(-1)
        continue
    l = li(n,a,b)
    print(*l)