N,Q = map(int, input().split())
ANS = (N-2)**2
R,C=N,N
RLEN=[]
CLEN=[]
for i in range(Q):
    RC,num = map(int, input().split())
    if RC==1:
        if R>num:
            for j in range(R-num-1):
                RLEN.append(C)
            ANS-=C-2
            R=num
        else:
            if len(RLEN)>0:
                ANS-=RLEN[N-num-1]-2
            else:
                ANS-=R-2
    else:
        if C>num:
            for j in range(C-num-1):
                CLEN.append(R)
            ANS-=R-2
            C=num
        else:
            if len(CLEN)>0:
                ANS-=CLEN[N-num-1]-2
            else:
                ANS-=C-2

print(ANS)

