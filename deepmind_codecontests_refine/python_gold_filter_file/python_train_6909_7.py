import sys
lines = sys.stdin.readlines()

(n,x) = map(int, lines[0].strip().split(" "))
nums = list(map(int, lines[1].strip().split(" ")))

minSoFar = min(nums)
index = -1
for i in range(x+n-1, x-1, -1):
    if nums[i%n] == minSoFar:
        index = i%n; break
tmp = nums[index]
num = tmp * n + (x-1+n-index) % n
for i in range(n):
    nums[i] -= tmp
for i in range(1, (x-1 + n - index) % n+1):
    nums[(i+index)%n] -= 1
nums[index] = num
print(" ".join(map(str, nums)))