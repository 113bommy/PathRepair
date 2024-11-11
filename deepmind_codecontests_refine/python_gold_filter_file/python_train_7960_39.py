def main():
	
	d = {'2':['2'],
		 '3':['3'],
		 '4': ['3','2','2'],
		 '5' :['5'],
		 '6' : ['5','3'],
		 '7' : ['7'],
		 '8' :['7','2','2','2'],
		 '9' :['7','3','3','2']
		 }
	n = int(input())
	a = list(input())
	res = []
	for x in a:
		if x not in ['0', '1']:				
			res = res + d[x]
	res = sorted(res)[::-1]
	print(''.join(res))




if __name__ == '__main__':
	main()