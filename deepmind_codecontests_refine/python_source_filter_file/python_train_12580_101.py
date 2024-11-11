n,k=map(int,input().split())
l=list(map(int,input().split()))
l.reverse()
print(sum(l[:k]))