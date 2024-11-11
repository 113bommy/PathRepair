n, k = list(map(int, input().split()))
s = list(input())
s0 = set(s)
dicter = dict()
for i in s0:
	dicter[i] = s.count(i)
mass = sorted(dicter.values(), reverse=True)
i = 0
count = 0
while k > 0:
	if mass[i] < k:
		k -= mass[i]
		count += mass[i] * mass[i]
	else:
		count += k * k
		k = 0
print(count)