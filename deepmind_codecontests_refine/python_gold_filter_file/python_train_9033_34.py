n,k=map(int,input().split())
h=list(map(int,input().split()))
h.sort()
print(sum(h[:max(0,n-k)]))