n = int(input())
nums = [int(i) for i in input().split()]
mx = 0
cr = 0
for i in range(n):
    if i == 0 or nums[i] > nums[i - 1]:
        cr += 1
    else:
        mx = max([cr, mx])
        cr = 0
mx = max([cr, mx])
print(mx)