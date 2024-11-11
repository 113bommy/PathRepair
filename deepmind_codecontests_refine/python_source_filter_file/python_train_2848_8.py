from itertools import permutations

n, k = [int(x) for x in input().split(" ")]
nums = [int(x) for x in input().split(" ")]

prev = nums[k-1]
exist = True

for i in range(k, n):
    if nums[i] != prev:
        exist = False
        break

if not exist:
    print(-1)
else:
    answer = 0
    for i in range(k-1, 0, -1):
        if nums[i] != prev:
            answer = i + 1
            break
    print(answer)
