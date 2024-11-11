import fractions


n,m=map(int,input().split())
A=list(map(lambda x: int(x)//2,input().split()))

lcm=A[0]
for i in range(1,n):
    lcm=lcm*A[i]//fractions.gcd(lcm,A[i])

if any([i for i in range(n) if lcm%(A[i]*2)==0]):
    print(0);exit()

ans=m//(2*lcm)
print(ans if m//lcm==0 else ans+1)