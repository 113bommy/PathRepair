from collections import deque
import sys
n, k = list(map(int, sys.stdin.readline().rstrip().split()))
qry = list(map(int, sys.stdin.readline().rstrip().split()))
msg = deque()
ids = dict()
for q in qry:
    try:
        t = ids[q]
    except KeyError:
        ids[q] = 1
        msg.appendleft(q)
        if len(msg) > k:
            d = msg.popleft()
            del ids[d]
print(len(msg))
for itm in msg:
    print(itm, end=" ")
print()