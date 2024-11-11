mod = 998244353
a, b, c, d = map(int, input().split())

dp0 = [0] * (c-a+1)
dp1 = [1]

for i in range(c-a):
    dp1.append(dp1[-1] * b % mod)

for j in range(1, d-b+1):
    new_dp0 = [(dp0[0] * a + dp1[0]) % mod]
    new_dp1 = [dp1[0] * (a-1) % mod]
    for i in range(1, c-a+1):
        new_dp0.append((dp0[i] * (a+i) + dp1[i]) % mod)
        new_dp1.append((new_dp0[-2] + new_dp1[-1]) * (b+j) % mod)

    dp0 = new_dp0
    dp1 = new_dp1

print(dp0[-1] + dp1[-1])