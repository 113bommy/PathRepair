a=int(input())
c=[[]for i in range(a)]
e=[]
g=0
h=[]
for i in range(a):
    b=input()
    e.append(b)
    for j in b:
        c[i].append(j)    
for i in range(len(c)):
    for r in range(len(c[i])):
        h.append(c[i][0-r-1])
    f=c[i][0]
    for q in e[i]:
        if q==f:
            g+=1
    if g!=len(e[i]):
        for j in range(len(c[i])-1):
            if c[i]!=h:
                print(e[i])
                break
            elif c[i][j]!=c[i][j+1]:
                c[i][j],c[i][j+1]=c[i][j+1],c[i][j]
                for i in c[i]:
                    print(i,end='')
                print()
                break
    else:
        print(-1)
    h=[]
        
