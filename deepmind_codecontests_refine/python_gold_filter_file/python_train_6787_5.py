a, b = map(int,input().split())
mod = 10**9+7
ans = 0

for n in [a,b]:

    A = [[0,0] for i in range(n)]
    A[0] = [0,1]
    if n > 1:
        A[1] = [1,1]
    for i in range(2,n):
        A[i][0] = sum(A[i-2]) % mod
        A[i][1] = sum(A[i-1]) % mod
    # print(A)
    ans += (sum(A[-1]) * 2) % mod

print((ans-2) % mod)