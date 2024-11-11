n,m,r=map(int,input().split())
l=list(map(int,input().split()))
ll=list(map(int,input().split()))
print((r//min(l))*max(ll)+(r%min(l)))