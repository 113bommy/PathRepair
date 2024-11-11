
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def II():
    return map(int,input().split())
def Ii():
    return int(input())
def infi():
    return float("Inf")
def mino():
    return -1
for ____ in range(Ii()):
    n,m=II()
    cs=0
    ml=0
    mr=0
    mu=0
    md=0
    cd=0
    s=input()
    for i in s:
        if i=='L':
            cs-=1
            if cs<ml:
                if mr-ml>=m-1:
                    break
                ml=cs
        if i=='R':
            cs+=1
            if cs>mr:
                if mr-ml>=m-1:
                    break
                mr=cs
        if i=='U':
            cd-=1
            if cd<ml:
                if md-mu>=n-1:
                    break
                mu=cd
        if i=='D':
            cd+=1
            if cd>md:
                if md-mu>=n-1:
                    break
                md=cd 
    print(1-mu,1-ml)