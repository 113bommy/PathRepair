import math
#print(math.gcd(968, 875))
def function(n, nums):
    if n==1:
        print(0)
        print(*nums)
    if n>1:
        c=0
        total=0
        ind=[]
        for i in range(1, len(nums)):
            if math.gcd(nums[i], nums[i-1])!=1:
                ind.append(i)
        #print(ind)
        if len(ind)>0:
            for i1 in range(len(ind)):
                ind[total]+=c
                nums.insert(ind[total], 1)
                total+=1
                c+=1
        print(total)
        print(*nums)



if __name__=="__main__":
    n=int(input())
    nums=list(map(int, input().rstrip().split()))
    function(n, nums)