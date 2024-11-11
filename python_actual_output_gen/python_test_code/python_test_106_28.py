def gcd(a,b):
    while min(a,b):
        if a>b:
            a,b=b,a
        b%=a
    return max(a,b)
def lcm(a,b):
    return a*b//gcd(a,b)
n,k=map(int,input().split())
if k>50 or k>=n:
    print('no')
else:
    for i in range(1,k+1):
        for j in range(i+1,k+1):
            if n%i==n%j:
                print('no')
                exit()
    print('yes')