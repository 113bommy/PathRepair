import fractions
 
n = int(input())
a = list(map(int, input().split()))
 
l = 1
for i in range(n):
	l = l // fractions.gcd(l, a[i])*a[i]
 
ans = 0
for i in range(n):
	ans += l//a[i]
print(ans%(10**9+7))