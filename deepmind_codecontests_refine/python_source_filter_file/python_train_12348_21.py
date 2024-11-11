#import os
n=int(input())
nums=map(int,input().split(" "))
nums=list(nums)
nums.sort()
if nums[n//2] == nums[n//2-1]:
    print("NO")
else:
    print("YES")
