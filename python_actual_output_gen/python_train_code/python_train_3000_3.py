import sys
nums = list(map(int, input().split(' ')))

if 1 in nums:
    print("YES")
    sys.exit()

if nums.count(2) == 2 or nums.count(2) == 1 and nums.count(4) == 2:
    print("YES")
    sys.exit()

if nums.count(3) == 3:
    print("YES")
    sys.exit()

print("NO")