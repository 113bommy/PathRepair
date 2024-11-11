t,s,x=map(int,input().split())
if ((x-t)%s==0 or (x-t)%s==1) and x>=t:
    if x-t>=s or x==t:
        print("YES")
    else:
        print("NO")
else:
    print("NO")
