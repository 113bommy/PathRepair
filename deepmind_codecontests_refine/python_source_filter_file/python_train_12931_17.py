mn=list(map(int,input().split()))
m,n=mn[0],mn[1]
ms=list(map(str,input().split()))
ns=list(map(str,input().split()))
q=int(input())
for i in range(q):
    a=int(input())
    f=ms[((a-1)%len(ms))]
    l=ns[((a-1)%len(ms))]
    print(f+l)
