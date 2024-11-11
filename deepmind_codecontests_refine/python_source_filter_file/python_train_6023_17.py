def calc(w, h):
	v = float('inf')
	a = w * h
	for i in range(h-1):
		h_a = w*i
		h_b = (h - i)//2*w
		h_c = a - h_a - h_b
		h_max = max(h_a, h_b, h_c)
		h_min = min(h_a, h_b, h_c)
		v = min(v, h_max - h_min)
		v_b = w//2*(h-i)
		v_c = a - h_a - v_b
		v_max = max(h_a, v_b, v_c)
		v_min = min(h_a, v_b, v_c)
		v = min(v, v_max - v_min)
	return v

def resolve():
	h, w = map(int, input().split())
	print(min(calc(h, w), calc(w, h)))
resolve()