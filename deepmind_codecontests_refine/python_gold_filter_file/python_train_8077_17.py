a,b = map(int,input().split())
for i in range(1,int((10**9)+1)):
	if i % 2 != 0: a-=i;
	else:b-=i;
	if b < 0:
		print("Valera")
		break
	if a < 0:
		print("Vladik")
		break