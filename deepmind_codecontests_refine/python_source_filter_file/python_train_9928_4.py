from collections import deque
def check(n):
    s=set([int(i) for i in str(n)])
    if len(s)<=2:
        return 1
    else:
        return 0
n=int(input())
s=set()
q=deque()
q.append(0)
while(len(q)>0):
    g=q.popleft()
    if g>=n:
        break
    s.add(g)
    if g>=n:
        break
    for j in range(0,10):
        if g*10+j not in s and check(g*10+j):
            q.append(g*10+j)

print(len(s)-1)