from math import pi
n=int(input())
sum=0
arr=list(map(int,input().split()))
arr=sorted(arr)
for i in range(0,len(arr)):
    if(i%2==1):
        sum-=arr[i]*arr[i]
    else:
        sum+=arr[i]*arr[i]
print(pi*sum)