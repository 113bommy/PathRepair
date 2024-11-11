N,M = map(int, input().split())
H = list(map(int, input().split()))
res = [1]*N
for i in range(M):
    a,b = map(int, input().split())
    if H[a-1] <= H[b-1]:
        res[a-1] = 0
    elif H[b-1] <= H[a-1]:
        res[b-1] = 0
print(sum(res))