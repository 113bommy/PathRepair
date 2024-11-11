for t in range(int(input())):
    n1=int(input())
    l1=list(map(int,input().strip().split()))
    n2=int(input())
    l2=list(map(int,input().strip().split()))
    o1=[]
    e1=[]
    o2=[]
    e2=[]
    for i in range(len(l1)):
        if(l1[i]%2==0):
            e1.append(l1[i])
        if(l1[i]%2==1):
            o1.append(l1[i])
    for j in range(len(l2)):
        if(l2[j]%2==0):
            e2.append(l2[j])
        if(l2[j]%2==1):
            o2.append(l2[j])
    a=len(o1)
    b=len(e1)
    c=len(o2)
    d=len(e2)
    if(a==0 or c==0):
        if(b==0 or d==0):
            print(0)
        else:
            print((b*d))
    if(b==0 or d==0):
        if(a!=0 and c!=0):
            print(a*c)
    if(a!=0 and b!=0 and c!=0 and d!=0):
        print(max(a,c)+max(b,d))