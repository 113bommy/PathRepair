N,M = map(int,input().split())
H = list(map(int,input().split()))
Y = [1]*N
for i in range(M):
    a,b = map(int,input().split())
    if H[a-1] <= H[b-1]:
        Y[a-1] *= 0
    if H[a-1] >= H[b-1]:
        Y[b-1] *= 0
print(Y.count(0))