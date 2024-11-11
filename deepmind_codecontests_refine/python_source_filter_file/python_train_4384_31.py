n,m,k=map(int,input().split())
s=0
for i in range(k):
    s+=2*(n+m-2)
    n-=2
    m-=2
print(s)
