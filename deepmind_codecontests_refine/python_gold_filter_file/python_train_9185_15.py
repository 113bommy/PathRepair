import sys
input=sys.stdin.readline
def bs(l,target,n):
    low=0
    high=n
    ans=-1
    while low<=high:
        mid=low+(high-low)//2
        if l[mid]<=target:
            ans=max(ans,mid)
            low=mid+1
        else:
            high=mid-1
    return ans
t=int(input())
for r in range(t):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    d={}
    start=[]
    end=[]
    i=0
    j=n-1
    while i<j:
        start.append(min(l[i],l[j])+1)
        end.append(max(l[i],l[j])+k)
        try:
            d[l[i]+l[j]]+=1
        except:
            d[l[i]+l[j]]=1
        i+=1
        j-=1


    start.sort()
    end.sort()
    mini=999999999999999
    for i in range(1,(2*k)+1):
        a=bs(start,i,len(start)-1)+1
        b=bs(end,i-1,len(end)-1)+1
        # print(a,b)
        one=a-b
        zero=0
        try:
            zero=d[i]
        except:
            pass
        twos=(n//2)-(one)
        ans=(twos*2)+(one-zero)
        # print("x: "+str(i)+" ans: "+str(ans))
        # print("0: "+str(zero)+" 1: "+str(one-zero)+" 2: "+str(twos))
        mini=min(mini,ans)
    print(mini)





