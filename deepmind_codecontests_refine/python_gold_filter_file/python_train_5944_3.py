n = int(input())
nums = [int(x) for x in input().split(' ')]
for i in range(n):
    if nums[i] % 2 == 0:
        nums[i] -= 1
print(*nums,sep=' ')
