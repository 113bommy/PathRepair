for _ in range(int(input())):
	n=int(input());a=input()
	print((n-min(a.rfind('1'),a.find('1')))*2 if '1' in a else n*2)