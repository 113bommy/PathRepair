last = ''
itog = ''
sumStart = 0
sum = 0
max = 0
k = 0
result = 0
resultS = ''
x = int(input())
s = str(x)
number = list(s)
#print(number)
for i in range(0,len(s)):
	sumStart = sumStart + int(s[i])
if x < 100:
	for i in range(0,x+1):
		a = i % 10
		b = i // 10
		if a + b >= max:
			max = a + b
			result = i
			itog = str(result)	
else:
	l = len(number)
	i = l - 1
	#print ('i = '+str(i))
	while i != 0:
		if number[i] != '9':
			#print ('i = '+str(i))
			m = i	
			if i > 0:
				if number[i] == '8':
					k = 0
					for j in range(1,m):
						if number[j] != '9':
							k = 1
						#print(j)
						#print(k)	
					if k == 1:
						#print('ya tut bil' + str(i))
						number[i] = '9'
						number[i-1] = str(int(number[i-1]) - 1)	
						i = i -1
						#print(number)
					else:
						i = i - 1				
				else:	
					number[i] = '9'
					number[i-1] = str(int(number[i-1]) - 1)	
					i = i -1
					#print(number)		
		else: 
			i = i - 1
	if number[0] == '0':
		number.remove('0')						
	for i in range(len(number)):
		itog = itog + number[i]
print(itog)
