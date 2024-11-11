ttt=int(input())
for tttt in range(ttt):
	nk=input().split(' ')
	n=int(nk[0])
	k=int(nk[1])
	s=input()

	m=round(n/k)
	a=[]
	for i in range(m):
		row=[]
		for j in range(k):
			row.append(s[(i*k)+j])
		a.append(row)
	q=0
	if(k%2==0):
		for i in range(round(k/2)):
			listt=[]
			for j in range(m):
				listt.append(a[j][i])
			for j in range(m):
				listt.append(a[j][k-i-1])
			sett=set(listt)
			count=[]
			for x in sett:
				count.append(listt.count(x))
			q+=len(listt)-max(count)
		print(q)
	else:
		for i in range(round((k-1)/2)):
			listt=[]
			for j in range(m):
				listt.append(a[j][i])
			for j in range(m):
				listt.append(a[j][k-i-1])
			sett=set(listt)
			count=[]
			for x in sett:
				count.append(listt.count(x))
			q+=len(listt)-max(count)
		listt=[]
		for j in range(m):
			listt.append(a[j][round(k/2)])
		sett=set(listt)
		count=[]
		for x in sett:
			count.append(listt.count(x))
		q+=len(listt)-max(count)
		print(q)
		

