x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if a<x:
    print("NO")
else:
    a-=x;
    if y<(a+c):
        print("NO")
    else:
        if z<(a+c-y):
            print("NO")
        else:
            print("YES")




