a = int(input())
for i in range (a+1, a+100) :
	j = str(i)
	w = j[0]
	x = j[1]
	y = j[2]
	z = j[3]
	if j.count(w) == j.count(x) == j.count(y) == j.count(z) == 1 :
		print (i)
		break
	else :
		pass