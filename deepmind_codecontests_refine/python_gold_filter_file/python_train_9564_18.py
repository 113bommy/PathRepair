h = []
for i in range(10):
	h.append(int(input()))
h.sort(reverse=True)
for i in range(3):
	print(h[i])