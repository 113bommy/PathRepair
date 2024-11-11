N,K=map(int,input().split())
n=list(map(int, input().split()))
m=n.sort()
print(sum(m[0:K]))
