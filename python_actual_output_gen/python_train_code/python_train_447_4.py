pre = [10**9]*7
last = [10**9]*7
n,x,y = [int(i) for i in input().split()]
nums = pre + [int(i) for i in input().split()] + last
ind = 7
if x == 0 and y == 0:
    print(1)
elif x == 0 or y == 0:
    for i in range(n):
        if x == 0 and nums[ind+i] < min(nums[ind+i+1:ind+i+1+y]):
            print(i+1)
            break
        elif y == 0 and min(nums[ind+i-x:ind+i]) > nums[ind+i]:
            print(i+1)
            break
else:
    for i in range(n):
        if min(nums[ind+i-x:ind+i]) > nums[ind+i] < min(nums[ind+i+1:ind+i+1+y]):
            print(i+1)
            break
