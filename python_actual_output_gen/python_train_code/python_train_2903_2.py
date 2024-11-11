I=input
pr=print
def solve():
	l = int(I())
	ar = list(map(int,I().split()))
	for i in range(l-2):
		try:
			if (ar.index(ar[i],i+1)-i > 1): pr("YES");return
		except:pass
	pr("NO")

for _ in range(int(I())):solve()