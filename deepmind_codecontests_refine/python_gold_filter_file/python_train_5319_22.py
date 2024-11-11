import math
def issuff(n,m,a,b,f):
    for i in range(n):
        if f>0:
            burn=(f+m)/a[i]
            f=round(f-burn,6)
            burn=(f+m)/b[(i+1)%n]
            f=round(f-burn,6)
        if f<0:
            return False
    
        
    return True

def answer(n,m,a,b):
    l=0.1
    r=1000000004
    ans=-1
    while r>=l:
        mid=round((r+l)/2,6)
        if issuff(n,m,a,b,mid):
            ans=mid
            r=mid-0.000001
        else:
            l=mid+0.000001
            
    
    return ans

n=int(input())
m=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
print(answer(n,m,a,b))