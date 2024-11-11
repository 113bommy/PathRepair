n = int(input())
x = input()
k = x.count("1")
s = int(x, 2)

def ev(n):
	cnt = 0
	while n != 0:
		m = bin(n).count("1")
		n = n % m
		cnt += 1
	return cnt

if k != 1:
	k1 = s%(k-1)
	k2 = s%(k+1)
	for i in range(n):
		if x[i] == "0":
			print(ev((k2+pow(2, n-i-1, k+1)) % (k+1))+1)
		else:
			print(ev((k1-pow(2, n-i-1, k-1)) % (k-1))+1)
else:
	k2 = s%(k+1)
	for i in range(n):
		if x[i] == "0":
			print(ev((k2+pow(2, n-i-1, k+1)) % k+1)+1)
		else:
			print(0)