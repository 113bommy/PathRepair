def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
	return a * b // gcd (a, b)

n = int(input())
A = list(map(int, input().split()))

ans = 1
for a in A:
    ans = (ans, a)
print(ans)
