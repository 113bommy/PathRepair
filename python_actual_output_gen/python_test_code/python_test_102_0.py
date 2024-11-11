n,m=map(int,input().split())
v=min(int(r)-int(l)+1 for i in m*'_' for l,r in [input().split()])
print(v,(list(range(v))*(n//v+1))[:n])