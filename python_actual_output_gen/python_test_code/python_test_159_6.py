n=int(input())
k=m=10**9
a=*map(int,input().split()),
for t in zip(a,a[:1:-1]):n-=1;m=min(m,*t);k=min(k,m//n)
print(k)