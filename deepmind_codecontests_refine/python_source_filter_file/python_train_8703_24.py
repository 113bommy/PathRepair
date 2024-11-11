l,r,x,y,k=map(int,input().split())
for i in range(l,r+1):
    if(i*k>=x and i*k<=y):
        print("YES")
        break
else:
    print("NO")