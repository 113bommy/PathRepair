t = int(input())
for _ in range(t):
    *nums, m = map(int, input().split())
    if sum(nums) - 3 < m:
        print('NO')
    elif sum(nums) - max(nums) + 1 + m >= max(nums):
        print('YES')
    else:
        print('NO')
