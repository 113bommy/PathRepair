n,k=map(int,input().split())
P=list(map(int,input().split()))
S=[0]*(n+1)
for i in range(n):
   S[i+1]=S[i]+P[i]
ans=0
for i in range(n-k+1):
   ans=max(ans,S[i+k]-S[i])
print((ans+k)//2)