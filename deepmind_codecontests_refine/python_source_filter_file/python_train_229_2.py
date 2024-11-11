for _ in range(int(input())):
    n=int(input())
    lastc,lastp=0,0
    ok=True
    for i in range(n):
        p,c=map(int,input().split())
        if(p<c):
            ok=False
        if(lastp>p or lastc>c):
            ok=False
        elif(lastp-p<lastc-c):
            ok=False

        lastc,lastp=c,p
    print("YES" if ok else "NO")