n=int(input())
nums=[int(x) for x in input().split()]
odd=0
even=0
for i in range(n):
    nums[i]=nums[i]%2
    if nums[i]==1:
        odd+=1
    else:
        even+=1
    if odd*even!=0 and abs(odd-even)>1:
        if odd>even:
            print(nums.index(0)+1)
            break
        else:
            print(nums.index(1)+1)
            break
    
    
    
