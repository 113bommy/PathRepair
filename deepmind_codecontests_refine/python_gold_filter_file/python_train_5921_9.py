w = int(input())
nums = list(range(w + 1))
for _ in range(int(input())):
    a, b = map(int, input().split(","))
    nums[a], nums[b] = nums[b], nums[a]
for x in nums[1:]:
    print(x)