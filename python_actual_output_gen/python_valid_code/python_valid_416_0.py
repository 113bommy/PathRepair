T_1, T_2 = map(int, input().split())
A_1, A_2 = map(int, input().split())
B_1, B_2 = map(int, input().split())

f = (A_1 - B_1) * T_1
s = (A_2 - B_2) * T_2

if f * (f + s) > 0:
	ans = 0
elif f * (f + s) == 0:
	ans = 'infinity'
else:
	ans = 1
	if f < 0:
		f *= -1
		s *= -1
	d = f + s
	div, mod = (f, abs(d))
	ans += div * 2
	if mod == 0:
		ans -= 1

print(ans)