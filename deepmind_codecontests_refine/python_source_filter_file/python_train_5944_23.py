def solve(nums):
    return [x if x % 2 != 0 else x-1 for x in nums]

n = input()

arr = list(map(int, input().split()))

print(solve(arr))