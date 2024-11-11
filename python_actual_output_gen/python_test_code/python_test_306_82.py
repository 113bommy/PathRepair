a=input()
a=a.split()
x,y=int(a[0]),int(a[1])
if x*y%2==0:
    print(x*y//2)
else:print(x*y//2-1)