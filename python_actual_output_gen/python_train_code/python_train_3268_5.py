def fair(a,b,n,m):
    j,c=0,0
    for i in range(m):
        while j<n:
            if b[i]>a[j]:
                c+=1
                j+=1
                break
            j+=1
    print(c)
    

ca=list(map(int,input().split()))
n,m=ca[0],ca[1]
a=list(map(int,input().split()))
b=list(map(int,input().split()))
fair(a,b,n,m)