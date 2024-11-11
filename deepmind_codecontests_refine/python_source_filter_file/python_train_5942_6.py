import math
while True:
	n = int(input())
	if n==0: break
	s = list(map(float, raw_input().split()))
	t = sum(s)
	a = t / n
	b = sum(map(lambda x: (x-a)**2, s))
	print(math.sqrt(b/n))