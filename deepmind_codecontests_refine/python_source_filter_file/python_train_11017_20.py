import sys
input = sys.stdin.readline
N=int(input())
a=list(map(int,input().split()))
A=0
amax=0
imax=0
for i in range(N):
    if A<abs(a[i]):
        A=abs(a[i])
        amax=a[i]
        imax=i+1
#print(imax,amax)
ans=[]
for i in range(N):
    ans.append([imax,i+1])
if amax>=0:
    for i in range(1,N):
        ans.append([i,i+1])
else:
    for i in range(1,N):
        ans.append([N-i+1,N-i])
print(len(ans))
for i in ans:
    print(*i)
