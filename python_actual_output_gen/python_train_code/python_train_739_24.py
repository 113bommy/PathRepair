n = input()

p = int(n)
def plus():
	#if l == 8:
		#print(10)
	#elif l > 8:
		#print(9)
	#elif l < 8:
		#print(8-l)
	c=0
	for x in range(p+1, p+11):
		c+=1
		if '8' in str(x):
			break
	print(c)
	
	
#def minus():
	#if l == 8:
		#print(10)
	#elif l > 8:
		#print(1)
	#elif l < 8:
		#print(2+l)
		
#if n[0] == '-':
	#minus()
#else:
	#plus()

plus()
