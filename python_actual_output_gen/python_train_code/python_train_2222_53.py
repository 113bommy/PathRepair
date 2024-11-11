n,m=map(int,input().split())
ll=[list(map(int,input().split())) for i in range(m)]

a=0
b=n
for l,r in ll:
 a=max(a,l)
 b=min(b,r)
print(b-a+1)