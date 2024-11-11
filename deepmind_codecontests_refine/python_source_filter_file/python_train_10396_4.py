N = int(input())
A = [(int(input()), 0) for i in range(N)]
B = [(int(input()), 1) for i in range(N)]
Object = sorted(A + B)
mod = 10 ** 9 + 7

ans = 1
memo = [0, 0]
for n, x in Object:
    if memo[1 - x] > 0:
        ans *= memo[1 - x] % mod
        memo[1 - x] -= 1
    else:
        memo[x] += 1

print(ans)
