n,k=map(int,input().split())
a=list(map(int,input().split()))
maxx=0
for b in range(k):
    maxx=max(maxx,abs(sum(x for i,x in enumerate(a) if i%k!=b)))
print(maxx)