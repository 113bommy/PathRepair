I = [int(_) for _ in open(0).read().split()]
N, T = I[:2]
A, B = I[2::2], I[3::2]
dp = [-1] * 6001
dp[0] = 0
for a, b in zip(A, B):
    dp_new = dp[:]
    for k in range(T):
        if dp[k] == -1:
            continue
        dp_new[k + a] = max(dp[k + a], dp[k] + b)
    dp = dp_new
print(max(dp))
