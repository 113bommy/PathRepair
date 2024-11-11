import sys
input=sys.stdin.readline
n,m,k=map(int,input().split())
x,s=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[0]+list(map(int,input().split()))
d=[0]+list(map(int,input().split()))
arr=sorted(list(zip(a,b)),key=lambda x:-x[1])
ans=n*x
j=0
for aa,bb in arr:
    while j<=k and d[j]+bb<=s:
        j+=1
    if j==0:
        continue
    ans=min(ans,aa*(n-c[j-1]))
print(ans)