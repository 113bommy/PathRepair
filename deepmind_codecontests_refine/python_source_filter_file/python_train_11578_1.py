import sys
input = sys.stdin.readline

m,n,k,t=map(int,input().split())
A=list(map(int,input().split()))
T=[tuple(map(int,input().split())) for i in range(k)]


seg_el=1<<((n+2).bit_length())
seg_height=1+(n+2).bit_length()
SEG=[0]*(2*seg_el) 
LAZY=[0]*(2*seg_el)

def indexes(L,R):
    INDLIST=[]

    R-=1
    
    L>>=1
    R>>=1

    while L!=R:
        if L>R:
            INDLIST.append(L)
            L>>=1
        else:
            INDLIST.append(R)
            R>>=1

    while L!=0:
        INDLIST.append(L)
        L>>=1

    return INDLIST

def updates(l,r,x): # 区間[l,r)をxに更新
        
    L=l+seg_el
    R=r+seg_el

    L//=(L & (-L))
    R//=(R & (-R))

    UPIND=indexes(L,R)
    
    for ind in UPIND[::-1]:
        if LAZY[ind]!=0:
            update_lazy = 1<<(seg_height - 1 - (ind.bit_length()))
            LAZY[ind<<1]=LAZY[1+(ind<<1)]=1
            SEG[ind<<1]=SEG[1+(ind<<1)]=update_lazy
            LAZY[ind]=0

    while L!=R:
        if L > R:
            SEG[L]=1<<(seg_height - (L.bit_length()))
            LAZY[L]=1
            L+=1
            L//=(L & (-L))

        else:
            R-=1
            SEG[R]=1<<(seg_height - (R.bit_length()))
            LAZY[R]=1
            R//=(R & (-R))

    for ind in UPIND:
        SEG[ind]=SEG[ind<<1]+SEG[1+(ind<<1)]

def getvalues(l,r): # 区間[l,r)に関するminを調べる

    L=l+seg_el
    R=r+seg_el

    L//=(L & (-L))
    R//=(R & (-R))

    UPIND=indexes(L,R)
    
    for ind in UPIND[::-1]:
        if LAZY[ind]!=0:
            update_lazy = 1<<(seg_height - 1 - (ind.bit_length()))
            LAZY[ind<<1]=LAZY[1+(ind<<1)]=1
            SEG[ind<<1]=SEG[1+(ind<<1)]=update_lazy
            LAZY[ind]=0
            
    ANS=0

    while L!=R:
        if L > R:
            ANS+=SEG[L]
            L+=1
            L//=(L & (-L))

        else:
            R-=1
            ANS+=SEG[R]
            R//=(R & (-R))

    return ANS

T.sort(key=lambda x:x[2],reverse=True)

OK=2*10**5+1
ind=0

for i in range(10,-1,-1):

    while ind<k and T[ind][2]>=i:
        updates(T[ind][0], T[ind][1]+1, 1)
        ind+=1

    if getvalues(0, n+2)*2+n+1<=t:
        OK=i
    else:
        break

ANS=0
for a in A:
    if a>=OK-1:
        ANS+=1
print(ANS)
