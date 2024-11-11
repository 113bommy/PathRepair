for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    mx=0
    cur=0
    for i in range(0,n-1,2):
        cur+=l[i+1]-l[i]
        cur=max(0,cur)
        mx=max(cur,mx)
    cur=0
    for i in range(0,n-1,2):
        cur+=l[i]-l[i+1]
        cur=max(0,cur)
        mx=max(cur,mx)
    s=0
    for i in range(0,n,2):
        s+=l[i]
    print(s+mx)