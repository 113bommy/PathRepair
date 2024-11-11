N,M,K=map(int,input().split())
P=1000000007
f=[0]*(N*M+1)
f[0]=1
for i in range(N*M):
    f[i+1]=(i+1)*f[i]%P
ans=0
for A in [N,M]:
    for i in range(1,A):
        ans = (ans+(N^M^A)**2*i*(i+1)//2)%P
print(ans*f[N*M-2]*pow(f[K-2],P-2,P)*pow(f[N*M-K],P-2,P)%P)