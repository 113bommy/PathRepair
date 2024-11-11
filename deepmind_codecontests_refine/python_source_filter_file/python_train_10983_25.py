if __name__ == '__main__':
	s = input()
	c = 0
	l = 0
	for i in s:
		if i.isupper():
			c+=1
		else:
			l+=1
	if l > c:
		print(s.upper())
	else:
		print(s.lower())