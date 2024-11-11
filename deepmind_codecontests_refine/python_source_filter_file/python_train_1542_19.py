N = int(input())
A = list(map(int, input().split()))

ans = [0] * N
for i in range(N,0,-1):
    ts = sum(ans[i:N:i])
    if ts % 2 != A[i-1]: ans[i-1] = 1

print(sum(ans))
for i in range(N):
    if ans[i] == 1: print(i+1,end=' ')
print()