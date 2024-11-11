x,y,z=map(int,input().split())
a=x-y-z
b=x-y+z
if a>0 and b>0:
    print("+")
elif b<0 and a<0:
    print("-")
elif a==0 and b==0:
    print("0")
else:
    print("?")

