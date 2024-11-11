l,r,x,y,k=map(int,input().split())
for i in range(l,r+1):
    if(i*k<=r and i*k>=l):
        print("YES")
        break
else:
    print("NO")