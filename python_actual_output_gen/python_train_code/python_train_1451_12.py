for i in range(0,int(input())):
    n,m=map(int,input().split())
    a=[]
    for j in range(0,n):
        b=input()
        a.append(list(b))
    c=0
    for j in range(0,m-1):
        if(a[0][j]=="D"):
            c+=1
    for j in range(0,n):
        if((a[j][-1])=="R"):
            c+=1
    print(c)