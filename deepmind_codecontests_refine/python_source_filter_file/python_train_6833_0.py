def my_power(n):
    ans=1
    for i in range(0,n):
        ans=ans*2
    return ans    
data=list(map(int,input().split(' ')))
if data[1]==1:
    print(data[0])
else:
    s=bin(data[0])
    print(my_power(len(s)-1)-1)
