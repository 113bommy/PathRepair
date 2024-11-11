
#a,b = map(int,input().split())

x = int(input())
s = 0

while True:
	if x-5 >=0:
		x -=5
		s+=1
		if x == 0:
			break

	else:		
		if x%2 == 0:
			if x-4 == 0:
				x-=4
				s+=1
				break
			
			else:
				x-=2
				s+=1
				break
		
		elif x%3 == 0:
			x-=3
			s+=1
			break
		
		else:
			x-=1
			s+=1
			break

print(s)



