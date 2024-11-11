M=998244353;n,A,B,K=map(int,input().split());F=[1];a=0
for i in range(n):F+=[F[-1]*(n-i)*pow(i+1,M-2,M)%M]
for i in range(n):
 r=K-i*A
 if(r%B==0)&(0<=r//B<=n):a+=F[i]*F[r//B]
print(a%M)