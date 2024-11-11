n,m = map(int,input().split())
L = [0]*m
R = [0]*m
for i in range(m):
    L[i],R[i] = map(int,input().split())

l = max(L)
r = min(R)

print(r-l+1)