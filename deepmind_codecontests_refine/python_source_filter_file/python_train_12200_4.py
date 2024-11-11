n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]


nums = [int((arr[0][1] * arr[0][2] // arr[1][2]) ** 0.5)]

for n in arr[0][1:]:
    nums.append(n // nums[0])
print(nums)
