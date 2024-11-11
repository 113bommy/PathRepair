y=int(input())

def is_b_year(x):
	s=set()
	for c in str(x):
		s.add(c)
	if len(s) == 4:
		return True
	else :
		return False

for x in range(y+1,2**31-1):
	if is_b_year(x):
		print(x)
		break
	
	
	

