m,n=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
e1=o1=e2=o2=0
for c in a:
    if c%2==0:
        e1+=1
    else:
        o1+=1

for d in b:
    if(d%2==0):
        e2+=1
    else:
        o2+=1

print(min(o1,e1)+min(o2,e2))