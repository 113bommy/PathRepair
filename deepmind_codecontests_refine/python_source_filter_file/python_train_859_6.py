pocet = int(input())
d = list(map(int, input().split(" ")))
if pocet == 1:
	print('0')
else: 
	rev = False
	n = 0
	res = []	
	for i in range(pocet-1):
		print(d)
		ind = d.index(i+1)
		ind2 = d.index(i+2)
		if ind != (ind2-1):
			n += 1
			if ind > ind2:
				doc = []
				if ind2 > 0:
					doc.append(str(ind2))
				if rev:
					doc.append(str(ind-ind2))
					doc.append(str(1))
					doc.append(str(i))
					if (ind+i) < (pocet - 1):
						doc.append(str(pocet-1-ind-i))
				else:
					doc.append(str(ind-i-ind2))
					doc.append(str(i+1))
					if ind < (pocet - 1):
						doc.append(str(pocet-1-ind))
				res.append(doc)
				rev = False
				#print(res)
			else:
				doc = []
				if rev:
					if ind > 0:
						doc.append(str(ind))
					doc.append(str(1))
					doc.append(str(i))
					doc.append(str(ind2-ind-i))
				else:
					if ind > i :
						doc.append(str(ind-i))
					doc.append(str(i+ind2-ind))
					doc.append(str(1))
				if ind2 < (pocet - 1):
					doc.append(str(pocet-1-ind2))
				res.append(doc)
				rev = True
				#print(res)
			docd = []
			inde = 0
			for j in reversed(range(len(doc))):
				for k in range(int(doc[j])):
					docd.append(d[len(d)-int(doc[j])+k-inde])
				inde += int(doc[j])
			d = docd
			print(d)
	if d.index(pocet-1) == 0:
		res.append(['1', str(pocet-1)])
		n += 1
	print(n)
	for re in res:
		print(len(re), end = " ") 
		print(" ".join(re))