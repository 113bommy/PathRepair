numbers = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13,'E':14,'F':15,'G':16,'H':17,'I':18,'J':19,'K':20,'L':21,'M':22,'N':23,'O':24,'P':25,'Q':26,'R':27,'S':28,'T':29,'U':30,'V':31,'W':32,'X':33,'Y':34,'Z':35}

def ConvertToDecimal(number, base):
	newnumber = 0
	for digit in range(-1,(0-len(number))-1,-1):
		if(numbers[number[digit]] >= int(base)):
			return -1
		newnumber += numbers[number[digit]]*(int(base)**(0-digit-1))
	return newnumber

a,b = [x for x in input().split(':')]
didmake = False
if(0<=ConvertToDecimal(a,60)<=23 and 0<=ConvertToDecimal(b,60)<=59):
	print(-1)
	didmake = True
else:
	for base in range(2,60):
		if(0<=ConvertToDecimal(a,base)<=23 and 0<=ConvertToDecimal(b,base)<=59):
			print(base, end = " ")
			didmake = True
			
if not didmake:
	print(0)