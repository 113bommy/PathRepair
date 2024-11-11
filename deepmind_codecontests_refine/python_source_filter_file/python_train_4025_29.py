from math import ceil
t = input()
H,D,C,N = map(int,input().split())
k = C*ceil((H/(N)))
if int(t[:2]) >= 20:
	print(C*ceil(H/N)*80/100)
else:
	if t[0] == "0" and t[3] == "0":
		l = int(t[1])
		l1 = int(t[4])
		if l1 == 0:
			l1 = 60
		else:
			l = l + 1
		l  = ((20 - l)*60 + (60-l1))*D
		k1 = (C*ceil((H+l)/N))*80/100
		if k > k1:
			print(k1)
		else:
			print(k)
	elif int(t[:2]) < 20:
		if t[3] == "0" and int(t[0]) != 0:
			l = (20-int(t[:2]))
			l1 = int(t[4])
			if l1 == 0:
				l1 = 60
			else:
				l = (20-int(t[:2])-1)
			l = l*60*D + (60-l1)*D
			k1 = (C*ceil(((H+l)/N)))*80/100
			if k > k1:
				print(k1)
			else:
				print(k)
		elif t[0] == "0" and int(t[3]) != 0:
			l1 = int(t[3:])
			l = (20-int(t[1])-1)
			l = (l)*60*D + (60-l1)*D
			k1 =  C*(ceil((H+l)/N))
			if k > k1:
				print((k1/1))
			else:
				print(k/1)
		elif t[0] != "0" and t[3] != "0":
			l1 = int(t[3:])
			l = (20-int(t[:2])-1)
			l = (l)*60*D + (60-l1)*D
			k1 =  C*(ceil((H+l)/N))*80/100
			if k > k1:
				print((k1)/1)
			else:
				print(k/1)

