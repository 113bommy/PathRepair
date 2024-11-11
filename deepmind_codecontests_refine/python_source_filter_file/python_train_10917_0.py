# AOJ 0005 GCD and LCM
# Python3 2018.6.9 bal4u

def lcm(a, b):
	return a/gcd(a, b)*b

def gcd(a, b):
	while b != 0:
		r = a % b
		a = b
		b = r
	return a

while True:
    try:
        a = list(map(int, input().split()))
        print(gcd(a[0], a[1]), lcm(a[0], a[1]))
    except EOFError:
        break
