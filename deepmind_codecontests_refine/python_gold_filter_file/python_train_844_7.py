if __name__ == '__main__':
	n = int(input())
	a = 'abcd'
	b =len(a)
	if n <=b :
		print(a[:n])
	else:
		s = n//b
		r = n%b
		print(a*s+a[:r])