import sys
input=sys.stdin.readline

fact=[1]
for i in range(1,15+1):
    fact.append(fact[-1]*i)

def generate_perm(n,m):
    ret=[]
    if n<=15:
        cand=[i+1 for i in range(n)]
    else:
        cand=[i+1 for i in range(n-15,n)]
    for i in range(1,min(15+1,n+1)):
        pos=m//fact[min(15,n)-i]
        m%=fact[min(15,n)-i]
        ret.append(cand[pos])
        del cand[pos]
    return ret

n,q=map(int,input().split())
ids=0
if n<=15:
    perm=[i+1 for i in range(n)]
else:
    perm=[i+1 for i in range(n-15,n)]
for _ in range(q):
    query=list(map(int,input().split()))
    if query[0]==1:
        l,r=query[1],query[2]
        if n<=15:
            print(sum(perm[l-1:r]))
        else:
            if l<=n-15:
                if r<=n-15:
                    print((r*(r+1))//2-(l*(l-1))//2)
                else:
                    print(((n-15)*(n-14))//2-(l*(l-1))//2+sum(perm[0:r-(n-15)]))
            else:
                print(sum(perm[l-1-(n-15):r-(n-15)]))
    elif query[0]==2:
        ids+=query[1]
        perm=generate_perm(n,ids)