n = int(input())
slices = list(map(int, input().split()))[::-1]
print(slices)
a, b = 0, 0

for c in slices:
	if b > a + c:
		a += c
	else:
		b, a = a + c, b
	#print(a, b)

print(a, b)