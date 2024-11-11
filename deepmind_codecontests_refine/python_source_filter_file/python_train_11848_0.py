N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

ans = 0
for i in range(N):
    tp = min(B[i],A[i])
    ans += tp
    B[i] -= tp
    tp = min(B[i], A[i+1])
    ans += tp
    A[i] -= tp
print(ans)
