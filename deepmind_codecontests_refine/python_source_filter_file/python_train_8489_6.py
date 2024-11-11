a,b,c=map(int,input().split())
z=[0]*a
for i in range(a):
    ok=0
    for j in range(b,-1,-1):
        if (sum(z)+j)/(a*b)<=c/100 :ok=j;break
    z[i]=ok
    if ok!=b:break
p=0
for i in range(a):
    if (sum(z)+1)/(a*b)==c/100:z[i]=0;p+=1
z[:p]=[]
z+=[0]*p
print(z)