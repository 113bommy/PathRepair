mod=10**9+7
comb1=1
comb2=1
N,K=map(int,input().split())
k=min(K,N-1)
x=0
for i in range(k):
 comb1=(comb1*(N-i)*pow(i+1,mod-2,mod))%(mod)
 comb2=(comb2*(N-1-i)*pow(i+1,mod-2,mod))%(mod)
 x+=(comb1*comb2)%(mod)
print((x+1)%(mod))
