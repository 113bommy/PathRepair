import sys
input = sys.stdin.readline
t = int(input())
from heapq import heappush, heappop
for i in range(t):
    n = int(input())
    A = list(map(int,input().split()))

    Q = []
    for i in A:
        heappush(Q, -i)
    if n == 1:
        print("T")
        continue
    a = -heappop(Q)
    b = -heappop(Q)
    # f = 0
    w = -1
    while len(Q) > 0:
        # print(len(Q),a,b)
        c = -Q[0]
        a -= b-c+1
        b -= b-c+1
        if c > a and c > b:
            # print("ab")
            if a > 0:
                heappush(Q, -a)
            a = -heappop(Q)
            if len(Q) == 0:
                w = 0 if a > b else 1
                break
            if b > 0:
                heappush(Q, -b)
            b = -heappop(Q)
        elif c > b:
            # print("b")
            if b > 0:
                heappush(Q, -b)
            b = -heappop(Q)
    if a > b:
        w = 1
    else:
        w = 0

    print("T" if w==1 else "HF")



