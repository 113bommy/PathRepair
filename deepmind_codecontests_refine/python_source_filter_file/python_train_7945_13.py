a=[]
for i in range(int(input())):
    x,y=map(int,input().split())
    a.append([x,y])
ans=0
for x,y in a:
    l,r,u,d=0,0,0,0
    for x1,y1 in a:
        if y==y1:
            if x>x1:l=1
            if x<x1:r=1
        if x==x1:
            if y>y1:d=1
            if y<y1:u=1
        if l==r==d==u==1: ans+=1
print(ans)
            
