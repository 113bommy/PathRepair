z,x,y=map(int,input().split())
c=set()
for i in range(z):
    a,b=map(int,input().split())
    if a-x==0:
        c.add(100000)
    else:
        c.add((b-y)/(a-x))
print(len(c))
         