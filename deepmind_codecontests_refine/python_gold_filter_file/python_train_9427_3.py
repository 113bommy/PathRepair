def fnd1(s,x):
    hi=len(s)-1
    lo=0
    ans=-1
    while hi>=lo:
        mid=(hi+lo)//2
        if s[mid]>=x:
            hi=mid-1
            ans=mid+1
        else: lo=mid+1
    return ans

def fnd2(s,x):
    hi=len(s)-1
    lo=0
    ans=-1
    while hi>=lo:
        mid=(hi+lo)//2
        if s[mid]<=x:
            lo=mid+1
            ans=mid+1
        else: hi=mid-1
    return ans

x,k=map(int,input().split())
s=[]
for n in range(x):
    p=input()
    s.append(len(p))
s.sort()
tar=len(input())
a=fnd1(s,tar)
b=fnd2(s,tar)
print(a+5*((a-1)//k),b+5*((b-1)//k))