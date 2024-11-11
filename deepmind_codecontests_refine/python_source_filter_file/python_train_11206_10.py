def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)
    
def lcm(a,b):
    return (a*b)//gcd(a,b)

def lcmn(n):
    a=[i+1 for i in range(n)]
    b=a[0]
    for i in range(1,n):
        b=lcm(b,a[i])
    return b

n,k=list(map(int,input().strip().split()))
if k>=43:
    print("No")
else:
    if n+1==lcmn(k) or k==1:
        print("Yes")
    else:
        print("No")