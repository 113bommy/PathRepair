n=int(input())
q=list(map(int,input().split()))
p=[0]
for i in range(n-1):
    p.append(p[i]+q[i])
s=sum(p)
#print(s)
#1 3 -3
k=n*(n+1)/2
r=range(1,n+1)
#print(*r)
#print(k,s)
x=(n+1)//2-s//n
p=[i+x for i in p]
if(sorted(p)==r):
    print(*p)
else:
    print(-1)