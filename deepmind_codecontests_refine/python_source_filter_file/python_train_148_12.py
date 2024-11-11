nums = [int(x) for x in input().split()]
print(sum(nums) // 5 if sum(nums) % 5 == 0 and sum(nums) == 0 else -1)
