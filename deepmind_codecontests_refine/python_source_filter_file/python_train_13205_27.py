from math import factorial

def getlist():
	return list(map(int, input().split()))

N, A, B = getlist()
v = sorted(getlist())

ans1 = 0
for i in range(A):
	ans1 += v[-1 - i]
ans1 = ans1 // A
print(ans1)

if v[-1] != v[- A]:
	i = 0
	while True:
		if v[- A + i] == v[- A]:
			i += 1
		else:
			 break
	ans2 = factorial(v.count(v[- A])) // factorial(i) // factorial(v.count(v[- A]) - i)

else:
	ans2 = 0
	n = v.count(v[-1])
	for i in range(A, B + 1):
		if v[- i] == v[- A]:
			ans2 += factorial(n) // factorial(n - i) // factorial(i)

		else:
			 break

print(int(ans2))