n,m=map(int, input().split())
w=list(map(int, input().split()))
ans=0.0
for i in range(m):
    u,v,c=map(int, input().split())
    ns=max(ans, round( (w[u-1]+w[v-1])/c,9))
print(ans)





