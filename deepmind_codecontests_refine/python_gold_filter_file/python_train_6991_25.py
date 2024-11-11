x,y,z=map(int,input().split())
a=x-y-z
b=x+z-y
if a>0 and b>0:
    print("+")
elif a<0 and b<0:
    print("-")
elif a==0 and b==0:
    print("0")
else:
    print("?")
