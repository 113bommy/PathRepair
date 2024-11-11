l=[]
for i in range(4):
    l.append(list(input()))
f=0
for i in range(3):
    for j in range(3):
        c=1
        x=l[i][j]
        if(l[i][j+1]==x):
            c+=1
        elif(l[i+1][j]==x):
            c+=1
        elif(l[i+1][j+1]==x):
            c+=1
        if(c==3 or c==1 or c==4):
            f=1
            break
    if(f==1):
        break
if(f==0):
    print("NO")
else:
    print("YES")
