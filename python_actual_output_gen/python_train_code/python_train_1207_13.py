x,y=[int(i) for i in input().split()]
s=input()
o=[]
for i in range(x):
    o.append(s[i])
for i in range(y):
    p=input().split()
    l=int(p[0])
    r=int(p[1])
    c1=p[2]
    c2=p[3]
    if l!=r:
        for i in range(l-1,r-1):
            if o[i]==c1:
                o.pop(i)
                o.insert(i,c2)
    else:
        if o[l-1]==c1:
            o.pop(l-1)
            o.insert(l-1,c2)
print("".join(o))