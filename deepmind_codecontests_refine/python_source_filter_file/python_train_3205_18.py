n,m = map(int,input().split())
H = list(map(int,input().split()))
p = [0]*n
for i in range(m):
    a,b = map(int,input().split())
    if H[a-1] >= H[b-1]:
        H[b-1] = -1
    if H[a-1] <= H[b-1]:
        H[a-1] = -1
print(p.count(0))
