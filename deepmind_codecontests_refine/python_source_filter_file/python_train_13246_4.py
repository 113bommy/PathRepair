for _ in range(int(input())):
    n=int(input())
    s=map(int,input().split())
    s=list(s)
    d=[1]*n
    for i in range(n//2,-1,-1):
        for nex in range(i+i+1,n,i+1):
            if s[i]<s[nex]:
                d[i]=max(d[i],1+d[nex])
    print(d[0])