l,d,v,g,r=map(int,input().split())
t=d/v
c=0
i1=0
i2=g
while(not(i1<=t and i2>=t)):
    c+=1
    if(c%2!=0):
        i1=i2
        i2=i2+r
    else:
        i1=i2
        i2=i2+g
if(i1==t or i2==t):
    c+=1

if(c%2!=0 and (i1==t or i2==t)):
    t=i2+r
elif(c%2!=0):
    t=i2
t+=(l-d)/v
print(t)