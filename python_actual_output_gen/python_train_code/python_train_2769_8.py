n=int(input())
nums=input().split()
for x in range(n):
    nums[x]=int(nums[x])
nums.sort()
if n==1 or n==2:
    print(sum(nums))
else:
    score=sum(nums)*n
    for i in range(n-2):
        score-=nums[i]*(n-i-2)
    print(score)
