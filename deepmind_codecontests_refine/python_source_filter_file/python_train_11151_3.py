s = 0
p = 998244353

a, b = map(int, input().split())
A = input()[::-1]
B = input()[::-1]
diff = b-a
count = 0
exp = 1

for i in range(b):
	if B[i]=='1':
		count += 1

for i in range(a):
	
	if A[i] == '1':
		val = (exp * count) % p
		s += val

	exp = exp*2 % p

	if count > 0:
		if B[i] == '1':
			count -= 1

print(s)