n, m  = map(int, input().split())
arr   = input().split()
index = [int(input()) for _ in range(m)]
nums  = [0] * n
d = {}

for i in range(len(arr)-1, -1, -1):
    if arr[i] not in d:
        d[arr[i]] = 1
        nums[(n-i-1)] += 1
    if len(nums) >= 2:
        nums[(n-i-1)] += nums[(n-i-2)]

print(*[nums[len(nums)-index[i]] for i in range(len(index))],sep='\n')