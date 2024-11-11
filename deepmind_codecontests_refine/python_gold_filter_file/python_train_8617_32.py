def initialize(N):
    i=1
    while i<N:
        i*=2
    return [0]*(2*i-1),i

def update(i,x):
    i+=d-1
    bit=ord(x)-97
    SEG[i]=0 | (1<<bit)
    while i>0:
        i=(i-1)//2
        SEG[i]=SEG[i*2+1]|SEG[i*2+2]
        
def find(a,b,k,l,r):
    if r<=a or b<=l:
        return 0
    if a<=l and r<=b:
        return SEG[k]
    else:
        c1=find(a,b,2*k+1,l,(l+r)//2)
        c2=find(a,b,2*k+2,(l+r)//2,r)
        return c1|c2
        
N=int(input())
S=input()
Q=int(input())

SEG,d=initialize(N)
for i in range(N):
    update(i,S[i])

for i in range(Q):
    com,s,t=map(str,input().split())
    if(com=='1'):
        update(int(s)-1,t)
    else:
        cnt=0
        bit=find(int(s)-1,int(t),0,0,d)
        while(bit>0):
            if(bit&1):
                cnt+=1
            bit//=2
        print(cnt)