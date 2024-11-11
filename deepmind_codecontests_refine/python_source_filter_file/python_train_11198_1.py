from sys import stdin
#n=int(stdin.readline().strip())
n,m=map(int,stdin.readline().strip().split())
l1=0
r1=0
t=10**7
s=[]
for i in range(m):
    l,r=map(int,stdin.readline().strip().split())
    s.append([l,r])
s.sort()
for i in range(m):
    l,r=s[i]
    if(r-l<t):
        l1=l
        r1=r
        t=r-l
        
ans=[0 for i in range(n)]
x=0
n1=r1-l1+1
for i in range(l1-1,l1+n-1):
   ans[i%n]=x%n1
   x+=1
print(r1-l1+1)
print(*ans)
#s=list(map(int,stdin.readline().strip().split()))
