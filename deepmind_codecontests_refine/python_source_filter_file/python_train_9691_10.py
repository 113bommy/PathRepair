if __name__ == '__main__':
	n,d = map(int, input().split())
	l = list(map(int, input().split()))
	x = []
	count= 0
	for i in range (n-1):
		if abs(l[i+1]-l[i]) == (2*d):
			count+=1
		elif (abs(l[i+1]-l[i])>(2*d)):
			count+=2
	print(count)
	