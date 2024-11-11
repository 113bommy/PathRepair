from itertools import accumulate as ac
N,K=map(int,input().split())
n=int(N**0.5)
mod=10**9+7
list_a=[1]*n
list_b=[N//j-N//(j+1) for j in range(1,N_s)]+[(N//n-n)]
list_p=[p for p in list_b]
list_aa=list(ac(list_a))
list_bb=list(reversed(list(ac(reversed(list_b)))))

for i in range(K-1):
    temp=sum(list_a)
    list_a=[(temp+list_bb[j])%mod for j in range(n)]
    list_b=[(list_p[j]*list_aa[j])%mod for j in range(n)]
    list_aa=list(ac(list_a))
    list_bb=list(reversed(list(ac(reversed(list_b)))))
    
print((sum(list_a+list_b))%mod)