class Rectangle:
	def __init__(self, l, r, t, b):
		self.l = l
		self.r = r
		self.t = t
		self.b = b
		self.store = [l,b,r,t]

	def error_check(self, other_rectangle):
		if self.l > other_rectangle.r:
			return False
		elif self.r < other_rectangle.l:
			return False
		elif self.t < other_rectangle.b:
			return False
		elif self.b > other_rectangle.t:
			return False
		else:
			return True

	def merge(self, other_rectangle):
		l = max(self.l, other_rectangle.l)
		r = min(self.r, other_rectangle.r)
		t = min(self.t, other_rectangle.t)
		b = max(self.b, other_rectangle.b)
		return Rectangle(l,r,t,b)

	def out(self):
		return (str(self.l) + ' ' + str(self.b))


n = int(input())
r_list = []

for i in range(0,n):
	temp = input().split()
	l = int(temp[0])
	r = int(temp[2])
	t = int(temp[3])
	b = int(temp[1])
	r_list.append(Rectangle(l,r,t,b))

pref = [None] * n
pref[0] = r_list[0]
for i in range (1,n):
	if pref[i-1].error_check(r_list[i]):
		pref[i] = pref[i-1].merge(r_list[i])
	else:
		pref[i] = None
		break

suf = [None] * n
suf[0] = r_list[n-1]
for i in range (1,n):
	if suf[i-1].error_check(r_list[n-2]):
		suf[i] = suf[i-1].merge(r_list[n-2])
	else:
		suf[i] = None
		break

i = 0
if suf[n-1-1]!=None:
	print(suf[n-1-1].out())
	raise SystemExit(0)

for i in range(1,n-1):
	if pref[i-1]!=None and suf[n-i-2]!=None:
		if pref[i-1].error_check(suf[n-i-2]):
			print(pref[i-1].merge(suf[n-i-2]).out())
			raise SystemExit(0)
			
i = n-1
if pref[n-1-1]!=None:
	print(pref[n-1-1].out())
	raise SystemExit(0)