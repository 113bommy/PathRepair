a,b = map(int,input().split())
while (a!=0)and(b!=0):
    if a>=2*b:
        a = a%b
    elif b>=2*a:
        b = b%a
    else:
        break
print(a,b)