n,k=map(int,input().split())
P=list(map(int,input().split()))
for i in range(n):
	P[i]-=1
C=list(map(int,input().split()))
ANS=-float('inf')
for i in range(n):
    snp=P[i]
    r=C[snp]
    L=[r]
    c=0
    np=P[snp]
    while True:
        if c==k-1:
            ANS=max(max(L),ANS)
            break
        if np==snp:
            y=k%(c+1)
            m=k//(c+1)
            if y==0:
                ANS=max(max(L),max(L)+(m-1)*L[-1],ANS)
                break
            else:
                #print(m,y)
                #print(L)
                ANS=max(max(L[:y]),max(max(L[:y]),0)+m*L[-1],ANS)
                break
        r+=C[np]
        L.append(r)
        np=P[np]
        c+=1
print(ANS)
