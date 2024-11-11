import sys
input = sys.stdin.readline

N=int(input())
S=list(input().strip())
Q=int(input())

LEN=N

BIT=[[0]*(LEN+1) for i in range(26)]

def update(v,w,i): # index vにwを加える
    while v<=LEN:
        BIT[i][v]+=w
        v+=(v&(-v)) # 自分を含む大きなノードへ. たとえばv=3→v=4

def getvalue(v,i): # [1,v]の区間の和を求める
    ANS=0
    while v!=0:
        ANS+=BIT[i][v]
        v-=(v&(-v)) # 自分より小さい2ベキのノードへ. たとえばv=3→v=2へ
    return ANS

for i in range(N):
    update(i+1,1,ord(S[i])-97)

for i in range(Q):
    qf,x,y=input().split()
    qf=int(qf)

    if int(qf)==1:
        x=int(x)
        update(x,-1,ord(S[x-1])-97)
        update(x,1,ord(y)-97)
        S[x-1]=y

    else:
        x=int(x)
        y=int(y)
        ANS=0
        for i in range(26):
            if getvalue(y,i)-getvalue(x-1,i)>0:
                ANS+=1

        print(ANS)
        
    
