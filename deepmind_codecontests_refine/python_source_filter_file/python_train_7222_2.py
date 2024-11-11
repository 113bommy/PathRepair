a=[]
for i in range(0,4):
    b=input()
    a.append(list(b))
i=0
flag=0
while i<3:
    j=0
    while j<3:
        c1=0
        c2=0
        if a[i][j]=='#':
            c1+=1
        else:
            c2+=1
        if a[i+1][j]=='#':
            c1+=1
        else:
            c2+=1
        if a[i][j+1]=='#':
            c1+=1
        else:
            c2+=1
        if a[i+1][j+1]=='#':
            c1+=1
        else:
            c2+=1
        #print(c1,c2)
        if c1==3 or c2==3:
            flag=1
            break
        j+=1
    i+=1
if flag==1:
    print("YES")
else:
    print("NO")