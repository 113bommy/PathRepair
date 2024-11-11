a=input()
a=a.split(' ')
a=[*map(int,a)]
b=a[1]
c=a[2]
d=a[3]
a=a[0]
e=c
f=d
g=[]
h=[]
while(e<=a):
    
    for o in range(d,f+1):
        if(o<e and o<=b):
            h.append(o)
            g.append(e)
    f=e
    e+=1
print(len(g))
for i in range(len(g)):
    print(g[i],h[i])
