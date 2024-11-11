n=int(input())
a=[]
for i in range(n):
    m=int(input())
    a.append(list(list(map(int,input().split())) for j in range(m)))
print(a)
ans=0
for i in range(2**n):
    r=1
    ib=list(format(i,"b").zfill(n))
    for j in range(n):
        if ib[j]=="1":
            for k in range(len(a[j])):
                if int(ib[a[j][k][0]-1])!=a[j][k][1]:
                    r=0
    if r==1:
        ans=max(ans,ib.count("1"))
print(ans)
