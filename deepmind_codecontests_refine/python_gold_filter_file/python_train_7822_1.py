n = int(input())
nums = list(map(int, input().split()))

moves = []
prev = float('-inf')
f = 0
e = len(nums)-1
while f <= e:
    if nums[f] < nums[e] and nums[f] > prev:
        moves.append("L")
        prev = nums[f]
        f += 1
        continue
    elif nums[e] > prev:
        moves.append("R")
        prev = nums[e]
        e -= 1
        continue
    elif nums[f] > prev and nums[e] < prev:
        moves.append("L")
        prev = nums[f]
        f += 1
    else:
        break
print(len(moves))
print(''.join(moves))
