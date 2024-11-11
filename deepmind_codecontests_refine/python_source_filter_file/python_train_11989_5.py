a=int(input())
b=[]
for i in range(0,a):
    b.append(input()[0:1])
c=[]
d=[]
count=0
for i in range(0,a):
    if(b[i] not in c):
        e=b.count(b[i])
        d.append(e)
        c.append(b[i])
for i in range(len(d)):
    x=d[i]//2
    y=d[i]-x
    if(x%2==0 and x>1):
        z=x//2
        w=(z-1)*x+1
        count=count+w
    elif(x>1):
        z=x//2
        w=(z-1)*x
        count=count+w
    if(y%2==0 and y>1):
        z=y//2
        w=(z-1)*y+1
        count=count+w
    elif(y>1):
        z=y//2
        w=z*y
        count=count+w
print(count)
        
        