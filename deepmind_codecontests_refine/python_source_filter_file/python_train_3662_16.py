import sys
import math
# n=int(sys.stdin.readline())
n,y=list(map(int,sys.stdin.readline().strip().split()))
a=list(map(int,sys.stdin.readline().strip().split()))
a.sort()
a.append(0)
# print(a)
y=y*8
arr=[]
i=0
k=2**(y//n)
# print(k)
while(i<n):
    # x=[a[i],1,math.ceil(math.log(a[i],2))+1]
    # x=[a[i],1]
    x=1
    # print(i)
    while(a[i]==a[i+1] and i<n):
        # x[1]+=1
        x+=1
        i+=1
        # print(i)
    arr.append(x)
    i+=1
# print(a,arr)
arr=[0]+arr
# print(arr)
for i in range(1,len(arr)):
    arr[i]=arr[i]+arr[i-1]
# print(arr)
op=n
# print(k)
if(sum(arr)<k):
    print(0)
    exit(0)
for i in range(1,len(arr)):
    # xxx=arr[i]-arr[min(i-1,i-k)]
    if(i<k):
        xxx=arr[i]-arr[i-1]
    else:
        xxx=arr[i]-arr[i-k]
    # print(xxx)
    op=min(op,n-xxx)
print(op)