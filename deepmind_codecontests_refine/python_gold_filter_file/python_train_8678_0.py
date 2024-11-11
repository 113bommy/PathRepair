import sys
input = sys.stdin.readline
#for _ in range(int(input())):
n=int(input())
ans=1
arr=[int(x) for x in input().split()]
for i in range(n):
    temp=set()
    d={}
    #ans=0
    for j in range(i+1,n):
        if arr[j]==arr[i]:
            temp=set()
        else:
            if arr[j] not in temp:
                if arr[j] in d:
                    d[arr[j]]+=1
                else:
                    d[arr[j]]=1
                temp.add(arr[j])
    number=-1
    maxi=-1
    #print(d,temp)
    for i in d:
        if maxi<d[i]:
            number=i
            maxi=d[i]
    #print(number,maxi)
    if number in temp:
        ans=max(ans,2*maxi)
    else:
        ans=max(ans,2*maxi+1)
d={}
for i in arr:
    if i in d:
        d[i]+=1
    else:
        d[i]=1
for i in d:
    ans=max(ans,d[i])
print(ans)