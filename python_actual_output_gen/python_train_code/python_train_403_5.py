import sys 
n,m=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))
for i in range(1,n):
    a[i]+=a[i-1]
ans=[0]*n
x=0
for i in range(n):
    c=a[i]//m
    ans[i]=c-x
    x+=c
print(*ans)
    