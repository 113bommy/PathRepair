(n,m)=list(map(int,input().split()))
s=[list(map(int,input().split())) for _ in range(n)]
flag=0
for i in range(n):
    if len(set(s[i]))!=1:
        flag=1
        break
if flag==0:
    a=0
    for j in range(n):
        a=a^s[j][0]
    if a==0:
        print('NIE')
        exit()
    else:
        print('TAK')
        print(' '.join(['1' for i in range(n)]))
        exit()
if flag==1:
    a=s[i][0]
    for j in range(m):
        if s[i][j]!=a:
            b=s[i][j]
            break
    x,y=0,0
    for t in range(n):
        x=x^s[t][0]
        if t==i:
            y=y^s[t][j]
        else:
            y=y^s[t][0]
    print('TAK')
    if x!=0:
        print(' '.join(['1' for i in range(n)]))
    else:
        s=['1' for i in range(n)]
        s[i]=str(j+1)
        print(' '.join(s))

    
                
