from functools import reduce
import io,os,sys,math
def binarySearchkeeb(data,target,low,high):
    if low > high:
        return high
    else:
        mid=(low+high)//2
        if data[mid] <=target:
            return binarySearchkeeb(data,target,mid+1,high)
        else:
            return binarySearchkeeb(data,target,low,mid-1)
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def gcd(x,y):return math.gcd(x,y)
def allFactors(n):
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
a,b=map(int,input().split())
re=list(allFactors(gcd(a,b)))
for _ in range(int(input())):
    l,h=map(int,input().split())
    ans=binarySearchkeeb(re,h,0,len(re)-1)
    if ans == -1:
        print(-1)
    else:
        c=re[ans]
        if l <= c:
            print(c)
        else:
            print(-1)
