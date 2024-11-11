
n = int(input())
list_n = input().strip().split()

nums = {}

for i in list_n:    
    nums[i] = len(nums)+1
    
x = int(input())
list_x = input().strip().split()

sum1 = 0
sum2 = 0
for i in list_x:
    sum1 += nums[i]
    sum2 += (n-nums[i])
    
print(sum1, sum2)
