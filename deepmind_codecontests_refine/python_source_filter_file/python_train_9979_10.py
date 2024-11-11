N = int(input())
K = eval("*".join(map(str,[*range(1, N+1)])))
ans = 1
for i in range (2, N + 1):
    num = 0
    while K % i == 0:
        num += 1
        K //= i
    ans *= (num + 1)

print(ans % (10**9 + 7))