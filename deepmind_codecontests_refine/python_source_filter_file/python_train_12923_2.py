def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

n,b=map(int,input().split())
prime=prime_factors(b)
minimum=10**12
for i in set(prime):
	total = 0
	num = prime.count(i)
	temp = n
	while temp != 0:
		temp //= i
		total += temp
	total //= num
	if total<minimum:
		minimum=total
print(minimum)