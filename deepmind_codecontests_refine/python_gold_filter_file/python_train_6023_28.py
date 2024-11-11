def min_value(w, h):
	ans = float('inf')
	for i in range(1, h):
		a = w*i
		v_t = (h-i)//2 * w
		v_b = (h-i)*w - v_t
		v_re = max(a, v_t, v_b) - min(a, v_t, v_b)
		h_l = (h-i)*(w//2)
		h_r = (h-i)*w-h_l
		h_re = max(a, h_l, h_r) - min(a, h_l, h_r)
		ans = min(ans, v_re, h_re)
	return ans

def resolve():
	h, w = map(int, input().split())
	a = min_value(w, h)
	b = min_value(h, w)
	print(min(a, b))
resolve()