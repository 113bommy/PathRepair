n=int(input())
k,m=0,10**9
a=*map(int,input().split()),
for t in zip(a,a[:n//2:-1]):n-=1;m=min(m,*t);k=max(k,m//n)
print(k)