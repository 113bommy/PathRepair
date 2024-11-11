def gcd(a,b):
    if a==0:
        return b
    elif b==0:
        return a
    elif a>b:
        return gcd(a-(a//b)*b,b)
    else:
        return gcd(b,b-(b//a)*a)
for i in range(int(input())):
    a,b=map(int,input().split())
    if gcd(a,b)==1:
        print('Finite')
    else:
        print('Infinite')