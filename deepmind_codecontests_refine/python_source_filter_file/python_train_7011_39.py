z=list(map(int,input().split()))
c=0
d=0
o=0
q=[]
for i in range(z[0]):
    for o in range(z[0]):
            q.append([i,o])

e=[]
for i in q:
    if i[0]**2+i[1]==z[0] and i[0]+i[1]**2==z[1] and i not in e:
        c+=1
        e.append(i)
print(c)