from sys import *
n,k=map(int,stdin.readline().split())
arr=list(map(int,stdin.readline().split()))
s=list(set(arr))
a=[]
d={}
for i in range(len(arr)):
    if arr[i] in d:
        d[arr[i]]+=1
    else:
        d[arr[i]]=1
for i in d:
    a.append([i,d[i]])
a.sort(key=lambda x:x[1])
a.reverse()
l=1
r=a[0][1]
my_ans=-1
while l<=r:
    mid=(l+r)//2
    tmp=k
    for i in range(len(a)):
        tmp-=(a[i][1]//mid)
        if tmp<=0:
            my_ans=mid
            break
    if tmp<=0:
        l=mid+1
    else:
        r=mid-1
if n==k:
    print(*arr)
else:
    ans=[]
    length=0
    for i in range(len(a)):
        for j in range(a[i][1]//my_ans):
            ans.append(a[i][0])
            length+=1
            if length==k:
                break
        if length==k:
            break
    print(*ans)