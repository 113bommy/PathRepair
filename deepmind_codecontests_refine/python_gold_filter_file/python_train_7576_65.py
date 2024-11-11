def gcd(a,b):
	return gcd(b,a%b) if b else a
n = int(input())
a = list(map(int,input().split()))
lcm = 1
for v in a:
	lcm *= v//gcd(v,lcm)
ans = 0
for v in a:
	ans += lcm // v
print(ans%1000000007)