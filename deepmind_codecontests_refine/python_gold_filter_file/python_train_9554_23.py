H, W, M = list(map(int, input().split()))
HW = set(tuple(int(x) - 1 for x in input().split()) for _ in range(M))
h = [0] * H
w = [0] * W
for hi, wi in HW:
	h[hi] += 1
	w[wi] += 1
hm = max(h)
wm = max(w)

hh = [i for i, v in enumerate(h) if v == hm]
ww = [i for i, v in enumerate(w) if v == wm]

ans = hm + wm - 1
for h in hh:
	for w in ww:
		if (h, w) not in HW:
			ans += 1
			break 	
	else:
		continue
	break
print(ans)
