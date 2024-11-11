q=int(input())
for t in range(q):
    n=int(input())
    a=list(map(int,input().split()))
    p=[]
    pod=1
    for i in range(1,n):
        if a[i]==a[i-1]:
            pod+=1
        else:

            p.append(pod)
            pod = 1
    p.append(pod)
    med=p[0]
    g=p[0]
    s=0
    uk1=1
    while uk1<len(p) and s<=g:
        s+=p[uk1]
        uk1+=1
    if s<=g or s+g>n//2:
        print('0 0 0')
    else:
        b=0
        while uk1<len(p):
            if b+g+s+p[uk1]<=n//2:
                b+=p[uk1]
                uk1+=1
            else:
                break
        if b<=s or b+g+s>n//2:
            print('0 0 0')
        else:
            print(g,s,b)

