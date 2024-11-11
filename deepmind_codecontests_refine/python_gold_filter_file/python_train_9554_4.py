h,w,m=(int(i) for i in input().split())
l1=[]
l2=[0]*h
l3=[0]*w
for i in range(m):
    x,y=(int(i) for i in input().split())
    l1.append((x,y))
    l2[x-1]+=1
    l3[y-1]+=1
m1=max(l2)
m2=max(l3)
m3=max(m1,m2)
if(m1>m2):
    l4=[0]*w
    k=l2.index(m1)
    for i in range(m):
        if(l1[i][0]!=k+1):
           l4[l1[i][1]-1]+=1
    k1=max(l4)
    print(m3+k1)
else:
    l4=[0]*h
    k=l3.index(m2)
    for i in range(m):
        if(l1[i][1]!=k+1):
           l4[l1[i][0]-1]+=1
    k1=max(l4)
    print(m3+k1)