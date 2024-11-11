import fractions
n=int(input())
a = list(map(int, input().split()))
ans = a[0]
for i in range(1, n):
    ans = ans * a[i] // fractions.gcd(ans, a[i])

count=0
for i in range(n):
  count+=(ans//a[i])
print(count%(10**9+7))
  
