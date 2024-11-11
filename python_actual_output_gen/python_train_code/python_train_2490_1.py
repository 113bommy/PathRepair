t=int(input())
for i in range(t):
    S=[]
    p=0
    p1=0
    p2=0
    np=0
    flag=0
    n=int(input())
    for j in range(n):
        S.append(input())
    for j in S:
        c1=j.count('0')
        c2=j.count('1')
        if c1%2==0 or c2%2==0:
           p=p+1
           if c1%2==0 and c2%2==0 :
                   p1=p1+1
        else:
           np=np+1


    while np>0 and np!=1 :
        np=np-2
        p2=p+2
    if(np==1 and p-p1>0):
        p=p+1
    print(p+p2)