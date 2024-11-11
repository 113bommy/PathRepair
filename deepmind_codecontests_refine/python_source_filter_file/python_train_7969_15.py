a=int(input())

def side(a):
	other=[a,0,0]
	if a==1 or a==2:
		return -1
	if a%2==1:
		other=str(int((a**2-1)/2))+" "+str(int((a**2+1)/2))
		return other
	elif a%2==0:
		if a%4==0:
			other=str(int(a*3/4))+" "+str(int(a*5/4))
			return other
		else:
			return str(int(((a/2)**2-1)))+" "+str(int(((a/2)**2+1)))
print (side(a))		