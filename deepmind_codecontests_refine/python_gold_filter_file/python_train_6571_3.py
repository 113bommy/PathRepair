xa,ya=list(map(int,input().split()))
xb,yb=list(map(int,input().split()))
xc,yc=list(map(int,input().split()))
a=[]
x1,y1=xa,ya
for x in range(min(xa,xb),max(xa,xb)+1):
    for y in range(min(ya,yb),max(ya,yb)+1):
        if abs(x-xc)+abs(y-yc)<abs(x1-xc)+abs(y1-yc):
            x1,y1=x,y
x,y=x1,y1
for i in range(min(x,xa),max(x,xa)+1):
    a.append([i,ya])
for i in range(min(y,ya),max(y,ya)+1):
    a.append([x,i])
for i in range(min(x,xb),max(x,xb)+1):
    a.append([i,yb])
for i in range(min(y,yb),max(y,yb)+1):
    a.append([x,i])
for i in range(min(x,xc),max(x,xc)+1):
    a.append([i,yc])
for i in range(min(y,yc),max(y,yc)+1):
    a.append([x,i])
a.sort()
a1=[]
for i in range(1,len(a)):
    if a[i]!=a[i-1]:
        a1.append(a[i-1])
a1.append(a[-1])
print(len(a1))
for i in a1:
    print(*i)