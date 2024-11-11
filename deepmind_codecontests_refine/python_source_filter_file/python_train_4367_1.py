#16D8101014F 久留米 竜之介 Python3
#a=[]
while(True):
	i=0
	tmp=0
	a=input().split('"') 
	aL=len(a)
	if a[0] ==".":
		break
	b=input().split('"')
	bL=len(b)
		
	if aL != bL:
		print("DIFFELENT")
	else:
		while(True):
			if a[i] != b[i]:
				print("DIFFERENT")
				break
			elif i > aL-2:
				if tmp==1:
					print("CLOSE")
					break
				else:
					print("IDENTICAL")
					break
			elif a[i+1] != b[i+1]:
				if tmp==1:
					print("DIFFERENT")
					break
				else: tmp=1
			i +=2
	
