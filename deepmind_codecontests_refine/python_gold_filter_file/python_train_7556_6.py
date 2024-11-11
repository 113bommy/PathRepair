a=input()
l=len(a)
if l!=1:
    b=10**(l-1)
    print(b-int(a[1:]))
else:print(1)