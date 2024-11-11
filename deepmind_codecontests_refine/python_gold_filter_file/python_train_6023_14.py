h, w = map(int, input().split())
div1 = 0
div2 = 0
if h%3==0 or w%3==0:
	print("0")
else:
	div1 = min(h, w)
	def div2(h, w):
		m = h*w
		for l in range(1, w):
			s = [l*h, (w-l)*(h-h//2), (w-l)*(h//2)]
			m = min(m, max(s)-min(s))
		return m
	div2 = min(div2(h, w), div2(w, h))
	print(min(div1, div2))
