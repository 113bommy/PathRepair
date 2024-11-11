import sys
from collections import deque
n = int(input())
q = deque()
for i in range(n):
    c = sys.stdin.readline()
    if c[0] == 'i':
        q.appendleft(c[7:])
    elif c[6] == ' ':
        try:
            q.remove(c[7:])
        except:
            pass
    elif c[6] == 'F':
        q.popleft()
    else:
        q.pop()
print(*q)