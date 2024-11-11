def cal(a):
    x=0
    while(a>0):
        x+=a%10
        a=a//10
    return x
n,s=input().split()
n=int(n)
s=int(s)
if((n-cal(n))<s):
    print(0)
elif((n-1-cal(n))<s):
    print(1)
else:
    u=10
    l=n
    mid=-1
    while(1):
        mid=(u+l)//2
        if((mid-cal(mid))>=s):
            if((mid-1-cal(mid-1))<s):
                break
            else:
                l=mid-1
        else:
            if((mid+1-cal(mid+1))>=s):
                mid+=1
                break
            else:
                u=mid+1
    print(n-mid+1)
                
        