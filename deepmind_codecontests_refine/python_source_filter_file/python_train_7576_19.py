#E
n=int(input())
a=tuple(map(int,input().split()))
import fractions
lcm=a[0]
b_sum=0
for i in range(1,n):
    lcm=lcm*a[i]//fractions.gcd(lcm,a[i])

num=10**9+7
for i in range(n):
    b_sum+=(lcm//a[i])%num

print(b_sum%num)