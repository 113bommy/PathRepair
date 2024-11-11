N, K, S = [int(i) for i in input().split()]
ans = [S] * K
ans += [10**5 if S != 10**5 else 10**5 -1] * (N - K)
print(ans)

