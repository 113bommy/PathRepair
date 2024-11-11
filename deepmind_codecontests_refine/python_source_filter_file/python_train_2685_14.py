import fractions

n, m = map(int, input().split())
a = list(map(int, input().split()))
def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)

def lcm(x, y):
	return (x * y) // gcd(x, y)

now = a[0]
for i in range(1, n):
	now = lcm(now, a[i])
	if now > m:
		print(0)
		exit(0)

for i in range(n):
	if (now//a[i])%2 == 0:
		print(0)
		exit(0)

print(((m//(now//2))+1)//2)
