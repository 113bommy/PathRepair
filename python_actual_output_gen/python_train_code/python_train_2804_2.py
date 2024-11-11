n = int(input())
ls = list(map(int, input().split()))
mem = {}
for i in ls:
    if i not in mem:
        mem[i] = 1
    else:
        mem[i] += 1
values = {}
lst = sorted(list(mem.keys()))
l = len(lst)
for i in lst:
    values[i] = i * mem[i]
dp = [[0, 0] for _ in range(l)]
dp[0] = [values[lst[0]], 0]
prev = lst[0]
for i in range(1, l):
    if lst[i] == prev + 1:
        dp[i] = [values[lst[i]] + dp[i - 1][1], max(dp[i - 1])]
    else:
        dp[i] = [values[lst[i]] + dp[i - 1][0], max(dp[i - 1])]
    prev = lst[i]
print(max(dp[l - 1]))