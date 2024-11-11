s, x1, x2 = map(int, input().split())
t1, t2 = map(int, input().split())
p, d = map(int, input().split())
def sol(x1, x2, p, d):
	tt = (x2-x1)*t2
	if d == 1 :
		if p < x1:
			tt = min(tt, (x2-p)*t1)
		else :
			tt = min(tt, (s-p)*t1+s*t1+x2*t1)
	if d == -1:
		tt = min(tt, p*t1+x2*t1)
	print(tt)
if x1>x2 :
	d = -d
	x1, x2 = s - x1, s-x2
	p = s -p
sol(x1, x2, p, d)
