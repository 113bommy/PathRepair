from math import gcd
def fun():
    n=int(input())
    arr=list(map(int,input().split()))
    whole=gcd(arr[0],arr[1])
    for i in range(2,n):
        whole=gcd(whole,arr[i])
    for i in range(n):
        arr[i]=arr[i]//whole
   
    prefix=[0]*n
    suffix=[0]*n
    prefix[0]=arr[0]
    suffix[-1]=arr[-1]
    for i in range(1,n):
        prefix[i]=gcd(prefix[i-1],arr[i])
    for i in range(n-2,-1,-1):
        suffix[i]=gcd(suffix[i+1],arr[i])
   
    ans=whole
    
    for i in range(1,n-1):
        ans*=gcd(prefix[i-1],suffix[i+1])

    ans*=prefix[n-2]
    ans*=suffix[1]

    return ans

print(fun())
