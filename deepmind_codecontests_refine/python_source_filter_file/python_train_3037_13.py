def oper(nums):
    if len(nums) == 1:
        return 0
    else:
        res = 0
        while True:
            if len(nums) == 1:
                break
            tmp = list()
            for i in range(0, len(nums), 2):
                if nums[i] + nums[i+1] >= 10:
                    res += 1
                tmp.append( (nums[i] + nums[i+1]) % 10 )
            nums = tmp
        return res

import sys
n = int(input())
num = list(map(int, sys.stdin.readline().rstrip().split(" ")))
dp = [0] * (n+1)
k = int(input())
dp[0] = num[0]
for i in range(1, n):
    dp[i] = dp[i-1] + num[i]
dp = [0] + dp
print(dp)
for i in range(k):
    st, ed = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    st -= 1
    print( (dp[ed] - dp[st]) // 10 )
