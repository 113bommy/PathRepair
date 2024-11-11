for i in range(int(input())):
    n=int(input())
    c=list(map(int,input().split()))
    o=list(map(int,input().split()))
    p=0
    j=0
    minc=min(c)
    mino=min(o)
    for j in range(n):
        q=min(c[j]-minc,o[j]-mino)
        i+=q
        c[j]-=q
        o[j]-=q
    for j in range(n):
        p+=((c[j]-minc)+(o[j]-mino))
    print(p)
