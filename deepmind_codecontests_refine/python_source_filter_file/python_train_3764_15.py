nums = list(map(int,input().split()))
nums = [ i-max(nums) for i in nums ]
nums.remove(0)
for i in nums:
    print(i,end=' ')

