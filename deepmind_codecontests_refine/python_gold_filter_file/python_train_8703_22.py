l,r,x,y,k=map(int,input().split())
if (x*k<r and y*k>l):
    if ((r//k)-((l-1)//k))>0 and r!=l:
        print("YES")
    elif l==r and l%k==0:
        print("YES")
    else:
        print("NO")
elif (x*k==r or y*k==l or x*k==l or x*k==r):
    print("YES")
else:
    print("NO")
