n,k=input().split(' ')
n=int(n)
k=int(k)
nums=list(map(int, input().split(' ')))
t=[]
nums=sorted(nums)
if k==0 and nums[0]==1:
    print ('-1')
elif k==0 and nums[0]!=1:
    print (nums[k-1]-1)
elif k!=0 and n!=1 and n!=k and nums[k-1]==nums[k]:
    print ('-1')
elif k!=0 and n!=1 and n!=k and nums[k-1]!=nums[k]:
    print (nums[k-1])
elif k==1 and n==1:
    print (nums[0])
elif n==k:
    print (nums[k-1])

