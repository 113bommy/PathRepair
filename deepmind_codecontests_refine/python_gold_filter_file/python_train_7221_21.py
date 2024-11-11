for i in range(5):
	l=input().split()
	if "1" in l:
		print(abs(l.index("1")-2)+abs(2-i))