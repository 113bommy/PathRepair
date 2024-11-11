from collections import deque
q=deque()
n,k=map(int,input().split(" "))
a=list(map(int,input().split(" ")))
if k>=n-1:
    print(n)
else:
    for i in range(n):
        q.append(i)
    x=q.popleft()
    np=0
    while (np<k):
        y=q.popleft()
        if a[x]>a[y]:
            np+=1
            q.append(y)
        else:
            np=0
            q.append(x)
            x=y
    print(a[x])
