h = []
for i in range(10):
	h.append(input())
h.sort(reverse=True)
for i in range(3):
	print(h[i])