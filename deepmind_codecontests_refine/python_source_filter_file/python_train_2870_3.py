n,m=map(int, input().split())
d=[]
k=0
for i in range(m):
    l,r=map(int, input().split())
    k=max(k, r-l)
print(k)
for i in range(n):
    print(i%k, end=' ')

