import sys
import math
from collections import defaultdict
def lower(arr,num):
    if num>arr[-1]:
        return len(arr)
    l,r=0,len(arr)-1
    ans=-1
    while l<=r:
        mid=(l+r)//2
        if arr[mid]<num:
            l=mid+1
            ans=mid
        else:
            r=mid-1
    return ans
def lowera(arr,num):
    if num>arr[-1]:
        return len(arr)-1
    l,r=0,len(arr)-1
    ans=-1
    while l<=r:
        mid=(l+r)//2
        if arr[mid]<=num:
            l=mid+1
            ans=mid
        else:
            r=mid-1
    return ans
t=int(sys.stdin.readline())
for _ in range(t):
    dic=defaultdict(int)
    n,k=map(int,sys.stdin.readline().split())
    arr=list(map(int,sys.stdin.readline().split()))
    small=[]
    large=[]
    l,r=0,n-1
    while l<=r:
        dic[arr[l]+arr[r]]+=1
        small.append(min(arr[l],arr[r]))
        large.append(max(arr[l],arr[r]))
        l+=1
        r-=1
    small.sort()
    large.sort()
    for i in range(len(small)):
        small[i]+=1
    for i in range(len(large)):
        large[i]+=k
    small=[small[0]-1]+small
    large=[large[0]-1]+large
    #print(small,'small')
    #print(large,'large')
    #print(dic,'dic')
    ans=1e10
    for i in range(2,2*k+1):
        #print(i,'i')
        a=lowera(small,i)
        b=lower(large,i)
        #print(a,'a',b,'b')
        #a-=1
        x=n//2-a
        if b<1:
            y=0
            b=0
        #print(x,'x',y,'y')
        s=x*2+a+y*2+b-dic[i]
        #print(s,'s')
        ans=min(ans,s)
    print(ans)
        
