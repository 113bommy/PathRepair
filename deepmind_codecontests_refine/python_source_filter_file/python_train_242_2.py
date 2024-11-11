# given a number n
# find three number smaller than equals to n (they don't have to be distinct)
# find these numbers such that the LCM is largest

n = int(input())

def gcd(a, b):
	if a>b:
		return gcd(b, a)
	if a==0:
		return b
	else:
		return gcd(b%a, a)

def lcm(a, b):
	return (a*b)//gcd(a,b)

mn = max(n-10, 1)
ans = 0
for i in range(n, mn, -1):
	for j in range(i-1, mn, -1):
		for k in range(j-1, mn, -1):
			# print(i, j, k)
			cur = lcm(lcm(i, j), k)
			if cur > ans:
				# print(cur)
				ans = cur

print(ans)
