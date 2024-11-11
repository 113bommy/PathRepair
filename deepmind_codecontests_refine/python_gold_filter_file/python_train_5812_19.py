N,T=map(int,input().split())
ans=2000
for i in range(N):
    a,b=map(int,input().split())
    if b<=T:ans=min(ans,a)
print(ans if ans<2000 else "TLE")
