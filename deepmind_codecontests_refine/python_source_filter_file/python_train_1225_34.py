N,K=map(int,input().split())
p=list(map(int,input().split()))
p.sort()
print(sum(p[0:K-1])