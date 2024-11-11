for _ in range(int(input())):
    n,k=map(int,input().split())
    if k%n==0:
        print(0)
    else:
        print(2)
    out=[]
    for i in range(n):
        out.append([0]*n)
    p=0
    q=0
    while k>0:
        k-=1
        out[p][q]=1
        p+=1
        q+=1
        q%=n
        if p==n:
            p=0
            q+=1
            q%=n
        #print(out,p,q)
    for i in range(n):
        for j in range(n):
            print(out[i][j],end=' ')
        print()