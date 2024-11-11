n,t=map(int,input().split())
ans=10000
for i in range(n):
    c,ti=map(int,input().split())
    if ti<=t:
        ans=min(ans,c)
print(ans if ans<10000 else "TLE")