a,b = map(int,input().split())

c = a
while(a>b):
    fac = a//b
    rem = a%b
    a = fac+rem
    c+=fac
    


print(c)
