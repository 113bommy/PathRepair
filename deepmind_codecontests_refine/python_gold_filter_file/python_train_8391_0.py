n,m=map(int,input().split())
n-=1
k=[]
f=[]
p=0
for i in range(m):
    q=list(map(int,input().split()))
    k.append(q[0])
    f.append(q[1])
for i in range(1,101):
    for j in range(m):
        if ((k[j]-1)//i)+1!=f[j]:
            break
    else:
        if not p:
            p=n//i+1
        else:
            q=n//i+1
            if p!=q:
                print(-1)
                exit()
print(p)
