n,a,b,c=map(int,input().split())
g=[input() for i in range(n)]
sousa=[]
for i in range(n):
    s=g[i]
    if s=="AB":
        if a==0 and b==0:print("No");exit()
        if a==1 and b==0:sousa.append("B");a=0;b=1
        elif a==0 and b==1:sousa.append("A");a=1;b=0
        else:
            if a>b:a-=1;b+=1;sousa.append("B")
            elif a==b and i<n-1 and g[i+1]=="BC":
                sousa.append("B");b+=1;a-=1
            else:b-=1;a+=1;sousa.append("A")
    elif s=="AC":
        if a==0 and c==0:print("No");exit()
        if a==1 and c==0:sousa.append("C");a=0;c=1
        elif a==0 and c==1:sousa.append("A");a=1;c=0
        else:
            if a>=c:a-=1;c+=1;sousa.append("C")
            elif a==c and i<n-1 and g[i+1]=="AB":
                sousa.append("A");a+=1;c-=1
            else:c-=1;a+=1;sousa.append("A")
    else:
        if b==0 and c==0:print("No");exit()
        if c==1 and b==0:sousa.append("B");c=0;b=1
        elif c==0 and b==1:sousa.append("C");c=1;b=0
        else:
            if c>=b:c-=1;b+=1;sousa.append("B")
            elif b==c and i<n-1 and g[i+1]=="AB":
                sousa.append("B");b+=1;c-=1
            else:b-=1;c+=1;sousa.append("C")
print("Yes")
for i in range(n):
    print(sousa[i])
