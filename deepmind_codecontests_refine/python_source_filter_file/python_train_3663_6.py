n=int(input())
l=list(map(int,input().split()))
y=list(set(l))
c=[]
s=0
x=0
for i in range(len(y)-1,-1,-1):
    for j in range(n):
        if(y[i]==l[j]):
            c.append(j+1)
            s=s+int(l[j]*x+1)
            x=x+1
print(s)
print(*c)
                
                
    