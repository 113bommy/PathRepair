n,k=map(int,input().split())
A=list(map(int,input().split()))

last=[-1]*(2*10**5+1)
nex=[-1]*n
prog=[0]*n

for i,a in enumerate(A*2):
    l=last[a]
    last[a]=i%n
    if nex[l]==-1 and l!=-1:
        nex[l]=(i+1)%n
        if i>=n or i+1==n:
            prog[l]=1
if nex[-1]==0:
    prog[-1]+=1

flag=False #いっぱいループ済か
stage=0
now=0
roop=[-1]*n
while True:
    if roop[now]!=-1 and flag==False:
        flag=True
        rr=stage-roop[now]
        stage=k-1-(k-1-stage)%rr
    if stage+prog[now]==k:
        break
    roop[now]=stage
    stage+=prog[now]
    now=nex[now]

A=A[now:]+A if k-1-stage else A[now:]
check=[0]*(2*10**5+1)
stack=[]
for a in A:
    if check[a]:
        while check[a]:
            check[stack.pop()]=0
        continue
    stack.append(a)
    check[a]=1

print(*stack)