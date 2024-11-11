length = int(input())
nums = input().split(" ", length - 1)
for i in range(length):
    nums[i] = int(nums[i])
swaps = []
inp = input()
for i in range(length - 1):
    swaps.append(int(inp[i]))

res = 1
currmin = 1
currmax = 1
currnums = [nums[0]]
for i in range(length - 1):
    if swaps[i] == 0:
        currmax = i + 1
        if min(currnums) < currmin or max(currnums) > currmax:
            res = 0
        print([currnums, currmax, currmin])
        currmin = i + 2
        currmax = i + 2
        currnums = [nums[i + 1]]
    else:
        currnums.append(nums[i + 1])
        currmax = i + 1
if res == 1:
    print("YES")
else:
    print("NO")
            