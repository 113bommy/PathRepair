x,y,x0,y0=map(int,input().split())
s1=input()
r=x*y
res="1 "
k=1
a = [[0] * y for i in range(x)]
a[y0-1][x0-1]=1
for i in range(len(s1)-1):
    if s1[i]=="U":
        if x0-1>=1 and k<r:
            x0=x0-1
            if a[x0-1][y0-1]==0:
                res=res+"1 "
                k=k+1
                a[x0-1][y0-1]=1
            else:
                res=res+"0 "
        else:
            res=res+"0 "
    if s1[i]=="D":
        if x0+1<=x and k<r:
            x0=x0+1
            if a[x0-1][y0-1]==0:
                res=res+"1 "
                k=k+1
                a[x0-1][y0-1]=1
            else:
                res=res+"0 "
        else:
            res=res+"0 "
    if s1[i]=="L":
        if y0-1>=1 and k<r:
            y0=y0-1
            if a[x0-1][y0-1]==0:
                res=res+"1 "
                k=k+1
                a[x0-1][y0-1]=1
            else:
                res=res+"0 "
        else:
            res=res+"0 "
    if s1[i]=="R":
        if y0+1<=y and k<r:
            y0=y0+1
            if a[x0-1][y0-1]==0:
                res=res+"1 "
                k=k+1
                a[x0-1][y0-1]=1
            else:
                res=res+"0 "
        else:
            res=res+"0 "
print(res+str(r-k))
