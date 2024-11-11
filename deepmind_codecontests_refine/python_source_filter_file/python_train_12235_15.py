n = int(input())
ans = 0
w = n-1
while (w>0):
	h = n - w - 1
	l = w - 1
	# print (h)
	# print (l)
	if (h>=1):
		t = 3 * (2**(h-1))
	else:
		t = 1
	if (l>=1):
		t *= 3 * (2**(l-1))
	# print (t)
	# print
	ans += t
	w-=1
ans *= 4
print(ans)