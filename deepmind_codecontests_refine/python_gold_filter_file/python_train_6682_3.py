S = sorted
M = lambda : map(int,input().split())
a = []
l,r = M()
def F(x):
	a.append(x)
	if x>r*10:
		return
	F(10*x+4)
	F(10*x+7)

F(0)
a=S(a)
def luckysum(p):
	s = 0
	for i in range(1, len(a)):
		s+= a[i]*(min(a[i],p)-min(a[i-1],p))
		if not (min(a[i],p)-min(a[i-1],p)):
			break
	return s

print(luckysum(r)-luckysum(l-1))

        