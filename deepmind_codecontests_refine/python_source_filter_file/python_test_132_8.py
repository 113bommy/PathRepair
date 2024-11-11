t=int(input())
for i in range(t):
    b=[]
    b=list(map(int,input().split()))
    c=[]
    c.append(b[0])
    c.append(b[1])
    for j in range(2,len(b)):
        if((c[0]+c[1] in b) and (c[0]+b[j] in b) and (c[1]+b[j] in b) and (c[0]+c[1]+b[j] in b)):
            c.append(b[j])
    for j in range(3):
        print(c[j],end=" ")
    print()