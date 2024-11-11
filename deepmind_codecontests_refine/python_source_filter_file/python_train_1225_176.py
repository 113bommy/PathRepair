n,k = map(int,input().split())
p = list(map(imt,input().split()))
p.sort()
print(sum(p[:k]))