import math

a = input()
b = input()
gcd = math.gcd(len(a), len(b))
ans = 0

for i in range(1, gcd + 1):
	if gcd % i != 0:
		continue
	if a[:i] != b[:i]:
		break
	A = len(a) // i
	B = len(b) // i
	if a[:i] * A == a and b[:i] * B == b:
		ans += 1
print(ans)
