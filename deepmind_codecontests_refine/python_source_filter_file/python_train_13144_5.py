def choose(n):
    if n<2:
        return 0
    return(n*(n-1))//2
t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(input())
    cs=[0]*(n+1)
    cs[0]=0
    for i in range(1,n+1):
        cs[i]=-1+cs[i-1]+int(arr[i-1])
    cs.sort()
    seen=[]
    seen2=[]
    ans=0
    print(cs)
    cur=cs[0]
    val=0
    for i in range(1,len(cs)):
        if cur==cs[i]:
            val+=1
        else:
            ans+=choose(val+1)
            val=0
            cur=cs[i]
    ans+=choose(val+1)
    print(ans)