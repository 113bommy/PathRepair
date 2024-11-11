t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    c={}
    for i in l:
        k=bin(i)[2:]
        if k in c:
            c[k]+=1
        else:
            c[k]=1
    ans=0
    for i in c:
        ans+=c[i]*(c[i]-1)//2
    print(ans)