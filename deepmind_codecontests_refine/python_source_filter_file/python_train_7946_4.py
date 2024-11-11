n, t1, t2, k = map(int, input().split())

growths = []
for i in range(n):
	a, b = map(int, input().split())
	growth = max(a*t1*(1-k/100) + b * t2, b*t1*(1-k/100) + a * t1)
	growths.append((i+1, growth))

for l in sorted(growths, key= lambda x: (-x[1], x[0])):
	print('{:d} {:.2f}'.format(l[0], l[1]))
	