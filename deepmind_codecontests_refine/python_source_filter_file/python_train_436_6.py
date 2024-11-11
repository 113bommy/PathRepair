import math
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    arr=[]
    for i in range(n):
        if a[i]!=-1 and ((i>=1 and a[i-1]==-1) or (i<n-1 and a[i+1]==-1) ):
            arr.append(a[i])
    if len(arr)==0:
        print(0,1)
        continue
    val=(min(arr)+max(arr))//2
    mx=-1
    for i in range(n-1):
        if a[i]!=-1 and a[i+1]!=-1:
            mx=max(abs(a[i]-a[i+1]),mx)
    aa=abs(val-arr[0])
    for i in range(len(arr)):
        aa=min(aa,abs(arr[i]-val))
    print(max(aa,mx),val)

