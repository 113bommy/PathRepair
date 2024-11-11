
h = []
for i in range(2):
	temp = 0
	g = list(map(int, input().split()))
	lst = list(map(int, input().split()))
	lst.reverse()
	for i in range(len(lst)):
		temp +=(lst[i] * (g[1] ** i))
	h.append(temp)
print(h)
if h[0] > h[1]:
	print('>')
elif h[0] < h[1]:
	print('<')
else:
	print('=')
