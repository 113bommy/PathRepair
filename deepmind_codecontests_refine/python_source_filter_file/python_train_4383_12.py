from copy import *
n=int(input())
arr=list(map(int,input().split()))
arr1=copy(arr)
arr1.sort()
j=n-1
k=0
for i in range(n-2,0,-1):
    if(arr1[j]>arr1[i]):
        j-=1
        k+=1
print(k)



