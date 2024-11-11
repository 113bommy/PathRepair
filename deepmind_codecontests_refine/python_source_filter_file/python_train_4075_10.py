from math import gcd
N = int(input())
ar = [int(x) for x in input().split()]
ar.sort()
a = ar[-1]
br = []
for i in range(N):
	if i > 0 and ar[i] == ar[i - 1]:
		br.append(ar[i])
	else:
		if(a % ar[i] == 0):
			br.append(ar[i])
b = 1
for i in br:
	b = (b * int(i)) // gcd(b, i)
print(a, b)