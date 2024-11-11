N,M=map(int,input().split())

mm=0
mx=10**5
for _ in range(M):
    l,r = map(int,input().split())
    mm = max(mm,l)
    mx= min(mx,r)
print(mx-mm+1)