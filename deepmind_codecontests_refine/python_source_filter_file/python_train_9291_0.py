for _ in range(int(input())):
    n,k=map(int,input().split())
    if k==0:
        x=0
        p=[['0' for j in range(n)] for i in range(n)]
    elif n*n==k:
        x=0
        p=[['1' for j in range(n)] for i in range(n)]
    elif n==k:
        x=0
        p=[['1' if i==j else '0' for j in range(n)] for i in range(n)]
    elif n>k:
        x=2
        p=[['1' if i==j and i<k else '0' for j in range(n)] for i in range(n)]
    else:
        if k/2==n:
            x=0
        else:
            x=2
        p=[['0' for i in range(n)] for j in range(n)]
        a=k//n
        b=k%n
        c=0
        #print(a,b,c)
        for i in range(n):
            for j in range(n):
                if i==j:
                    if c<b:
                        for z in range(a+1):
                            p[i][(j+z)%n]='1'
                        #print(p[i])
                        c+=1
                    else:
                        for z in range(a):
                            p[i][(j+z)%n]='1'
                            
    print(x)
    for i in range(n):
        print(''.join(p[i]))
                            
                            
                            
                            