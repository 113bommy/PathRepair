N = int(input())
ans = 0
n = 1
while n*n < N:
    if (N-n)%n == 0:
        m = (N-n)//n
        if m <= n: break
        ans += m
    n += 1
print(ans)