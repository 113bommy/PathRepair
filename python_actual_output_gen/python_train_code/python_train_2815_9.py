N=int(input())
p_max=int((-1+(1+4*N)**0.5)/2)
ans=0

for p in range(1,p_max+1):
    if (N-p)%p ==0 and (N-p)//p >= 1:
        ans += (N-p)//p

print(ans)