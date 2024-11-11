a,b,c=map(int,input().split())
d=a-b
if abs(d)<=c:
    if c==0:
        print("0")
    else:
        print("?")
else:
    if d>0:
        print("+")
    elif d<0:
        print("-")
    else:
        print("0")