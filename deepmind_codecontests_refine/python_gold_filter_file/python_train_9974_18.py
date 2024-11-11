from fractions import gcd


N=int(input())
A=list(map(int,input().split()))

total=0
left=[0]*(N+1)
right=[0]*(N+1)

for i in range(N):
    left[i+1]=gcd(left[i],A[i])
    right[N -i - 1] = gcd(right[N-i], A[N-1-i])

for i in range(N):
    total=max(total,gcd(left[i],right[i+1]))

print(total)