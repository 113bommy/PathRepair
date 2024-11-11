from collections import deque
a = input()
n=len(a)
r=deque()
for i in a:
    if len(r)<1 or i>=r[0]:
        r.appendleft(i)
print("".join(r))
    
