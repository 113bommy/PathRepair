n=int(input())
l=[]
for _ in range(n):
    l.append(input())
ans=True
for i in range(n):
    for j in range(n):
        c=0
        if(l[i][j-1]=="o" and j-1>=0):
            print(i,j,"left")
            c+=1
        try:
            if(l[i][j+1]=="o"):
                print(i,j,"right")
                c+=1
        except:
            pass
        try:
            if(l[i+1][j]=="o"):
                print(i,j,"down")
                c+=1
        except:
            pass
        try:
            if(l[i-1][j]=="o" and i-1>=0):
                print(i,j,"up")
                c+=1
        except:
            pass
        if(c%2!=0):
            print("NO")
            ans=False
            break
    if(not ans):
        break
else:
    print("YES")
