n = int(input())

cl = []

for i in range(n):
    cl.append(int(input()))


ans = [1 for i in range(n)]

mod = 1**9+7

stones = dict()

stones[cl[-1]] = n-1

for i in range(n-1):
    cur = cl[n-i-2]

    if cur in stones and stones[cur] != n-i-1:
        ans[n-i-2] = ans[n-i-1] + ans[stones[cur]]
        ans[n-i-2] %= mod
    else:
        ans[n-i-2] = ans[n-i-1] % mod
    stones[cur] = n-i-2

print(ans[0])
