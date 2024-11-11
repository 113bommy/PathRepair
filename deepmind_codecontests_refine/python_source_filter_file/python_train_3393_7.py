def read(i,s):
	return s[i:]+s[:i]

def shift(initialstr, l, length):
	for i in range(length):
		tempstr = read(i, l)
		if(tempstr == initialstr):
			return i
	return -1 

def func():
	n=int(input())
	l=[]
	for i in range(n):
		l.append(input())
	length = len(l[0])
	totalmin=999
	if(n==1):
		print("0")
		return
	for i in range(length):
		initialstr = read(i, l[0])
		curmin = i
		for j in range(1,n):
			temp = shift(initialstr, l[j], length)
			if(temp == -1):
				print("-1")
				return
			else:
				curmin+=temp
		if(curmin<totalmin):
			totalmin=curmin
	print(totalmin)

func()