def gcd(a, b):
    return a if b==0 else gcd(b, a%b)
    
a, b = map(int, input().split())
c, d = map(int, input().split())
g = gcd(a, c)
dif = abs(b-d)
if dif%g==0:
	for t in range(min(b, d), 1000000):
		if (t-b)%a==0 and (t-d)%c==0:
			print(t)
			break
else:
	print(-1)