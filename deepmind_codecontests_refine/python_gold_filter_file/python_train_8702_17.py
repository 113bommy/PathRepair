x1,y1,x2,y2=(int(x)for x in input().split(" "));
x,y=(int(x)for x in input().split(" "));

def abs(a):
    if(a<0): return -a;
    return a;

if((x1-x2)%x!=0 or (y1-y2)%y!=0):
    print("NO");
else:
    a=abs(x1-x2)//x;
    b=abs(y1-y2)//y;
    if((a&1)==(b&1)): print("YES");
    else: print("NO");
