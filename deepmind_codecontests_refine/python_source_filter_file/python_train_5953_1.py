import sys
input = sys.stdin.readline

n=int(input())
L=list(input().split())

#n=2*10**5
#L=["aaa","bbb"]*(10**5)


ANS=[L[0]]
LEN2=len(L[0])

mod0=1<<16
mod1=(1<<16)-3
mod2=(1<<16)-2
p=75

TABLE0=[0]
TABLE1=[0]
TABLE2=[0]

def hash_ij0(i,j): # [i,j)のハッシュ値を求める
    return (TABLE0[j]-TABLE0[i]*pow(p,j-i,mod0))%mod0

def hash_ij1(i,j): # [i,j)のハッシュ値を求める
    return (TABLE1[j]-TABLE1[i]*pow(p,j-i,mod1))%mod1

def hash_ij2(i,j): # [i,j)のハッシュ値を求める
    return (TABLE2[j]-TABLE2[i]*pow(p,j-i,mod2))%mod2

for s in L[0]:
    TABLE0.append((p*TABLE0[-1]%mod0+ord(s)-48)%mod0)
    TABLE1.append((p*TABLE1[-1]%mod1+ord(s)-48)%mod1)
    TABLE2.append((p*TABLE2[-1]%mod2+ord(s)-48)%mod2)


for i in range(1,n):
    NEXT=L[i]
    LEN=len(NEXT)

    ha0=0
    ha1=0
    ha2=0

    plus=-1

    #print(NEXT)

    for j in range(min(LEN,LEN2)):
        ha0=(p*ha1%mod0+ord(NEXT[j])-48)%mod0
        ha1=(p*ha1%mod1+ord(NEXT[j])-48)%mod1
        ha2=(p*ha2%mod2+ord(NEXT[j])-48)%mod2

        #print(ha1,TABLE1)
        #print(hash_ij1(LEN2-j-1,LEN2))

        if ha0==hash_ij0(LEN2-j-1,LEN2) and ha1==hash_ij1(LEN2-j-1,LEN2) and ha2==hash_ij2(LEN2-j-1,LEN2):
            plus=j

    #print(plus)

    if plus==-1:
        ANS.append(NEXT)
        LEN2+=len(NEXT)

        for s in NEXT:
            TABLE0.append((p*TABLE0[-1]%mod0+ord(s)-48)%mod0)
            TABLE1.append((p*TABLE1[-1]%mod1+ord(s)-48)%mod1)
            TABLE2.append((p*TABLE2[-1]%mod2+ord(s)-48)%mod2)
            
    else:
        NEXT=NEXT[plus+1:]

        ANS.append(NEXT)
        LEN2+=len(NEXT)

        for s in NEXT:
            TABLE0.append((p*TABLE0[-1]%mod0+ord(s)-48)%mod0)
            TABLE1.append((p*TABLE1[-1]%mod1+ord(s)-48)%mod1)
            TABLE2.append((p*TABLE2[-1]%mod2+ord(s)-48)%mod2)

sys.stdout.write("".join(ANS)+"\n")
        
    
