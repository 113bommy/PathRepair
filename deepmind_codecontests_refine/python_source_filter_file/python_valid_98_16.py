t=int(input())
for i in range(t):
    n=int(input())
    a=input()
    flag=False
    for j in range(n):
        p=0
        q=0
        for k in range(j,n):
            if a[k]=="a":
                p+=1
            else:
                q+=1
            if p==q:
                flag=True
                break
        if flag==True:
            break
    if flag==True:
        print(p,q)
    else:
        print(-1,-1)
