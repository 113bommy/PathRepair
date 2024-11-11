from sys import stdin, stdout
t=int(stdin.readline())
for _ in range(t):
    p,f=map(int,input().split())
    ns,na=map(int,input().split())
    sw,aw=map(int,input().split())
    total=0
    if p<f:
        t=p
        p=f
        f=t

    if sw>aw:
        t=aw
        aw=sw
        sw=t
        t=ns
        ns=na
        na=t

    for i in range(0,ns+1):
        if i*sw>p:
            continue
        pa=min((p-i*sw)//aw,na)
        fs=min(f//sw,ns-i)
        fa=min((f-fs*sw)//aw,na-pa)
        t=i+pa+fs+fa
        if t>total:
            total=t
    print(total)

