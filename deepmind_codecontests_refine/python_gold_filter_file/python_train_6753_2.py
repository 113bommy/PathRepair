from sys import exit
n, m = map(int, input().split())
a = list(map(int, input().split()))

odd = []
even = []
for x in a:
	if x%2 == 0:
		even.append(x)
	else:
		odd.append(x)

if n%2 == 0:
	if len(odd) > 2:
		print("Impossible")
		exit()
	if len(odd) == 2:
		a = [odd[0]] + even + [odd[1]]
		b = [odd[0]+1] + even + [odd[1]-1]
		if b[-1] == 0:
			b.pop()
	else:
		a = even
		b = [1] + even
		b[-1] -= 1
		if b[-1] == 0:
			b.pop()

else:
	if len(odd) > 1:
		print("Impossible")
		exit()
	if m == 1:
		b = [1, n-1]
	else:
		a = odd + even
		b = [odd[0]+1] + even
		b[-1] -= 1
	if b[-1] == 0:
		b.pop()

print(*a)
print(len(b))
print(*b)