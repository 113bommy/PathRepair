
N = int(input())

list = []

for i in range(N):
	list.append(input())

list.sort()

d = 0
j = 0
count = 0

def function(number):
	if( number % 2 == 0 ):
		return((number/2)*((number/2)-1))

	else:
		return(((number+1)/2)*(((number+1)/2)-1)/2 +((number+1)/2 - 1)*(((number+1)/2)-1-1)/2 )



while( j+1 < len(list) ):
	if( list[j][0] == list[j+1][0] ):
		count += 1
	

	if( list[j][0] == list[j+1][0] and j + 1 == len(list) - 1 ):
		d += function(count+1)

	elif( list[j][0] != list[j+1][0] ):
		d += function(count+1)

		count = 0
	j += 1

print(d)