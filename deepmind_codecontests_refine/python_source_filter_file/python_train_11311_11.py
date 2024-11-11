a,b=map(int,input().split())
#a,b=12,5
while a!=0 and b!=0:
    if a>=2*b:
        a=a%2*b
        continue
    if b>=2*a:
        b=b%2*a
    else:
        break
print(a,b)