x=int(input())
y=input()
a=[0]*10
for i in range(len(y)):
    if(y[i]=="L"):
        a[a.index(0)]=1
    elif(y[i]=="R"):
       a.reverse()
       a[a.index(0)]=1
       a.reverse()
    elif(y[i]!="L" and y[i]!="R"):
        a[int(y[i])]=0  
print(*a , sep='')
