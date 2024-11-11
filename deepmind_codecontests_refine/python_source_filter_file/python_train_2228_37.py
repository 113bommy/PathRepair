x,y=[int(i) for i in input().split()]
l=[int(i) for i in input().split()]
l.sort()
o=[]
for i in range(y-x+1):
    a=min(l[i:i+4])
    b=max(l[i:i+4])
    o.append(b-a)
print(min(o))