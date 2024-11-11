import math

t = int(input())

for rr in range(t):
	oc = int(input())
	fl = False
	if oc != 0:
		for i in range(2,32000):
			sq1 = i
			v1 = sq1*sq1 - oc
			if v1 > 0 and int(math.sqrt(v1))**2 == v1:
				sv1 = int(math.sqrt(v1))
				l = 2
				r = sq1
				while (r-l) > 1:
					mid = int((l+r)/2)
					vc = int(sq1/mid)
					if (sq1*sq1 - vc*vc) > oc:
						r = mid - 1
					else:
						l = mid
				cr = int(sq1/r)
				cl = int(sq1/l)

				if (sq1*sq1 - cr*cr) == oc and r <= sq1:
					fl = True
					st = str(sq1) +' '+ str(r)
					print(st)	
					break 
				elif (sq1*sq1 - cl*cl) == oc and l <= sq1:
					fl = True
					st = str(sq1) +' '+ str(l)
					print(st)
					break

	if not fl:
		if oc == 0:
			print("1 1")
		else:
			print(-1)

	

	