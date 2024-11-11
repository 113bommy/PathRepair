N,M,K=map(int,input().split())
O,S,T=10**9+7,N+M,6
for i in range(K):S=S*(N*M-i)%O;T*=i+1
print(S*K*~-K*pow(T,O-2,O)%O)