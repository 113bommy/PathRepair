l,r,x,y,k=[int(a) for a in input().split()]
i=l
j=y
s=0
while(i<=r and j>=x):
    d=(i/j)
    if(d==k):
        s=1
        break
    elif(d<k):
        i=i+1
    else:
        j=j+1
if(s):
    print("YES")
else:
    print("NO")
