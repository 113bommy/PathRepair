N, M = map(int,input().split())
H = list(map(int,input().split()))
ans = [0]*N
for _ in range(M):
    A, B = map(int,input().split())
    if H[A-1] > H[B-1]:
        ans[A-1] = 1
    if H[A-1] < H[B-1]:
        ans[B-1] = 1
print(ans.count(1))