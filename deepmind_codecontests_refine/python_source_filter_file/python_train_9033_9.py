n,k=map(int,input().split())
h=list(map(int,input().split()))
h.sort(reverse=True)
del h[5]
print(sum(h))