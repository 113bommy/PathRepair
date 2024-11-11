from collections import  deque
N,u,v=map(int,input().split())
u-=1
v-=1

L=[list() for _ in range(N)]
for _ in range(N-1):
    a,b=map(int,input().split())
    a-=1
    b-=1
    L[a].append(b)
    L[b].append(a)

q=deque([(v,0)])
T=[-1]*N
A=[-1]*N

while q:
    p,x=q.pop()
    A[p]=x
    for to in L[p]:
        if A[to]==-1:
            q.append((to,x+1))

q=deque([(u,0)])
while q:
    p,x=q.pop()
    T[p]=x
    for to in L[p]:
        if T[to]==-1 and A[to]>x+1:
            q.append((to,x+1))


Tcan=[i for i,x in enumerate(A) if x!=-1]
cnt,gi=max([(A[i], i) for i in Tcan]+[(0,0)])
if cnt==0:
    print(0)
    exit()
print(A[gi]-1)
