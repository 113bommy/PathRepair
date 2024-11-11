a,b=map(int,input().split())
g=-1
z=0
for i in range(a):
    y,x=map(int,input().split())
    if y<b and g<100-x and x>0:
        g=100-x
        z=1
    if g==-1:
        if x==0:
            g=0
print(g)