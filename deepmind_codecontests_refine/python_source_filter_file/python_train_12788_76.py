A,B,C,D,E,F=map(int,input().split())
X=F//100
w,s=100*A,0
for x in range(X,0,-1):
    a,b=0,0
    while A*a<=x:
        b=(x-A*a)%B
        if b==0:
            break
        a+=1
    if b==0:
        b=(x-A*a)//B
        maxs=F-100*(A*a+B*b)
        c,d=0,0
        cc=0
        while C*cc<=maxs:
            dd=(maxs-C*cc)//D
            if C*cc+D*dd>C*c+D*d:
                c,d=cc,dd
            cc+=1
        if s/w<(C*c+D*d)/(100*(A*a+B*b)+C*c+D*d):
            s,w=C*c+D*d,100*(A*a+B*b)+C*c+D*d
print(w,s)