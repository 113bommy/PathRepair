b,k=map(int,input().split(' '))    
nums=list(map(int,input().split(' ')))
if b%2==0:
    ans=sum(nums)%2
else:
    ans=nums[-1]%2
if ans==0:
    print('even')
else:
    print('odd')