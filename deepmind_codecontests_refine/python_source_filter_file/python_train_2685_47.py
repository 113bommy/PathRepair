judge=0
N,M = map(int,input().split())
import fractions
a = list(map(int, input().split()))
ans = a[0]
for i in range(1, N):
    ans = ans * a[i] // fractions.gcd(ans, a[i])
for j in a:
    if (ans//j)%2==0:
        judge=1
        sss=0
        break
if judge==0 and (M-ans)//2 <0:
    sss=0
elif judge==0 and (M-ans) >=0:
    sss=((M-ans//2)//ans)+1
print(sss)