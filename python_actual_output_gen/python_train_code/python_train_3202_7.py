n,m,k=map(int,input().split())
ns=list(map(lambda x:int(x),input().split()))
ns.sort()
ns.reverse()
if m<k:
    print(0)
else:
    m=m-k+1
    i=0
    while i<len(ns):
        m-=ns[i]
        if m<1:
            print(i+1)
            break
        i+=1
        m+=1
    else:
        print(-1)