N,K=map(int,input().split())
A=list(map(int,input().split()))
mod=10**9+7

NOW=[0]*(K+1)
NOW[0]=1#そこまでi個使ったときの場合の数


for i in range(N):
    NEXT=[0]*(K+1)
    NOWSUM=[0]
    for n in NOW:
        NOWSUM.append(NOWSUM[-1]+n)
        
    for j in range(K+1):
        NEXT[j]=(NEXT[j]+NOWSUM[j+1]-NOWSUM[max(0,j-A[i])])%mod

    NOW=NEXT
    #print(NOWSUM,NOW)

print(NOW[K])