from itertools import accumulate
n,k = map(int, input().split())
nums = [int(x) for x in input().split()]
nums.sort(reverse=True)
falta = [nums[0]-i for i in nums]
acc = list(accumulate(falta))
#print(falta, acc)
rx, ry = 0,0
for i, nu in enumerate(nums):
    lo, hi = i, n-1
    while(hi> lo):
        mid = (hi+lo+1)//2
        if acc[mid]-acc[i]-(mid-i)*falta[i]<=k:
            lo=mid
        else:
            hi=mid-1
    if lo-i >= rx:
        rx,ry = lo-i+1, nums[i]
print(rx,ry)

