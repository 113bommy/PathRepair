t=int(input())
res=[]
for i in range(t):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    k=sum(a)
    if(k)>=m:
        res.append(m)
    else:
        res.append(k)
for i in range(len(res)):
    print(res[i])