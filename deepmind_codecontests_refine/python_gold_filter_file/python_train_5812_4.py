N,T=map(int,input().split())
s=2000
for i in range(N):
    a,b=map(int,input().split())
    if b<=T:s=min(s,a)
print(s if s<2000 else "TLE")
