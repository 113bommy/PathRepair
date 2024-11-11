n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7
C = [0] * (n + 1)
C[0] = 3
ans = 1
for i in a:
    ans = ans * C[i] % MOD
    C[i] -= 1
    C[i+1] += 1
print(ans % MOD)
