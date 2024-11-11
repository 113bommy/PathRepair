def gcd(a,b):
    while b:
        a%=b
        a,b=b,a
    return a
a,b,c,d=map(int,input().split())
if a/b<c/d:
    d1 = b * c-a*d
    e = b*c
    f = gcd(d1, e)
    print(str(d1//f)+'/'+str(e//f))
elif a/b>c/d:
    d1=a*d-b*c
    e=a*d
    #print(e)
    f=gcd(d1,e)
    #print(f)
    print(str(d1//f)+'/'+str(e//f))
else:
    print('0/1')