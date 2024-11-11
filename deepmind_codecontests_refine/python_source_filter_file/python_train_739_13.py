def bins(x,n,nums):
    res=0
    ln=len(nums)-1
    for l in range(n):
        if x%2==0:
            res-=nums[ln]
        else:
            res+=nums[ln]
        x//=2
        ln-=1
    return res
binr=[]
x=int(input())
nums=[]
for n in range(x):
    nums.append(int(input()))
for n in range(2**x):
    binr.append(bins(n,x,nums))
    if bins(n,x,nums)==0 or bins(n,x,nums)==360:
        print("YES")
        exit(0)
print("NO") 
