n=int(input())
for o in range(n):
    n=int(input())
    l=list(map(int,input().split()))
    xor=0
    s=sum(l)
    for i in l:
        xor^=i
    req=s+xor
    print(2)
    print(str(s)+" "+str(req))
    