from collections import deque
n,q = map(int,input().split())
a = deque(list(map(int,input().split())))
M = [int(input()) for i in range(q)]
m = sorted([ M[i] for i in range(q)])
d = []

if q == 0:
    exit()
ma = max(a)
c = 0
cnt = 0
for i in range(n):
    if a[0] == ma:
        break
    A = a.popleft()
    B = a.popleft()
    d.append([A,B])
    if A > B:
        a.appendleft(A)
        a.append(B)
    else:
        a.appendleft(B)
        a.append(A)

    cnt += 1
cnt += 1
print(d)
for i in range(c,q):
    if M[i] >= cnt:
        print(ma, a[1 + ((M[i] - cnt) % (n-1))])
    else:
        print(d[M[i]-1][0],d[M[i]-1][1])
