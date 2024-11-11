h1,a1,c1=[int(i) for i in input().split()]
h2,a2=[int(i) for i in input().split()]
c=0
l=[]
while h2>0:
    if h2-a1<=0:
        h2-=a1
        l.append("STRIKE")
    elif h1>a2:
        h2-=a1
        h1-=a2
        l.append("STRIKE")
    else:
        h1+=c1
        l.append("HEAL")
    c+=1
print(c)
for i in l:
    print(i)
    
        
