n,k=map(int,input().split())
p=list(map(int,input().split()))
p2=p.sort()
print(sum(p2[:k]))