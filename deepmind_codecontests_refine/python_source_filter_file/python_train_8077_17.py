a,b=map(int,input().split())
i=0
while i<a or i<b:
	if a>=i:
		a-=i
	else:
		print("Vladik")
		break
	i+=1
	if b>=i:
		b-=i
	else:
		print("Valera")
		break
	i+=1
	if a<i:
		print("Vladik")
		break