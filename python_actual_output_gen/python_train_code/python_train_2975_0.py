def gcd(a, b):
	return b if a == 0 else gcd(b % a, a)
	

l1, r1, t1 = map(int, input().split())
l2, r2, t2 = map(int, input().split())

g = gcd(t1, t2)
d = l2 - l1
s = d % g
#print(g, d, s)

ans1 = min(r1 - l1 - s, r2 - l2) + 1
s = (g - s) % g
#print(s)
ans2 = min(r1 - l1, r2 - l2 - s) + 1

print(max(ans1, ans2))
#print(ans1, ans2)