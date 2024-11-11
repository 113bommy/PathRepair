n = int(input().strip())
order = dict()
nums = [(int(i),index) for index,i in enumerate(input().strip().split())]
nums.sort()
order = [i[1] for i in nums]
nums = [i[0] for i in nums]
dp = [100000010000 for i in range(n + 1)]
dp[0] = 0
p = [-1 for i in range(n + 1)]
for i in range(n + 1):
    for j in range(3,6):
        if i + j <= n:
            diff = nums[i + j  - 1] - nums[i]
            if dp[i + j] > dp[i] + diff:
                p[i + j] = i
                dp[i + j] = dp[i] + diff
cur = n
cnt = 0
ans = dict()
while cur != 0:
    for i in range(cur - 1,p[cur] - 1, -1):
        ans[order[i]] = cnt
    cnt += 1
    cur = p[cur]
print(dp[n],ans[order[0]] + 1)
for i in range(n):
    print(ans[i] + 1,end = ' ')
print()
#print(' '.join(str(ans[i]) for i in range(n)))
