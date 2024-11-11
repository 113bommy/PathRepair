n,a,b=map(int,input(),split())
ans=N//(A+B)*A
r=N%(A+B)
ans+=min(r,A)

print(ans)

