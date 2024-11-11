n = int(input())
l = list(map(int,input().split()))
def jebaj(d, k):
	res = 0
	pyk = d[0]%k
	for i in range(n - 2):
		res += min(pyk, k - pyk)
		pyk = (pyk + d[i+1])%k
	res += min(pyk, k - pyk)
	return res
s = sum(l)
out = 10000000000000000000000000
import math
if s <= 1:
	print(-1)
else:
    i = 2
    ss = s
    primes = []
    while ss > 1 and i * i <= s:
        if ss%i == 0:
            ss //= i
            if len(primes) == 0 or i != primes[-1]:
            	primes.append(i)
        else:
            i += 1
    if ss * ss > s:
    	primes.append(ss)
    for i in primes:
    	out = min(out, jebaj(l, i))
    print(out)