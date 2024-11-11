n = int(input())
nums = [int(j) for j in input().split()]
ref = 3000 * [0]
for j in range(n):
    ref[nums[j] - 1] += 1
output = -1
for j in range(3000):
    if ref[j] == 0:
        output = j + 1
        break
print(output)
