n = int(input())
ans = 1
for i in range(n//2):
    ans *= (n-i)
    ans //= (i+1)
ans //= 2
a = (n // 2) - 1

if a - 2 < 0:
    print(ans)
else:
    tmp = 1
    tmp = a*(a-1)
    for i in range(a-2):
        tmp *= (i+1)

    print(ans*(tmp**2))
