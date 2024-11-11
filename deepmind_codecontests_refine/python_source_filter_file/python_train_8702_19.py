x1,y1,x2,y2 = map(int,input().split())
a = abs(x1-x2)
b = abs(y1-y2)
x,y = map(int,input().split())
if(a%x!=0 or b%y!=0):
    print("NO")
else:
    par1 = a/x
    par2 = b/y
    par1 = par1%1
    par2 = par2%1
    if par1!=par2:
        print("NO")
    else:
        print("YES")
