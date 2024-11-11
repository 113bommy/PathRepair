a = list(map(int,input().split()))
segment,triangle = False,False
for i in range(len(a)):
	for j in range(len(a)):
		for k in range(len(a)):
			if(a[i]+a[j]>a[k] and a[i]+a[k]>a[j] and a[j]+a[k]>a[i] and i != j and j != k and k!=i):
				triangle = True
				break
			elif(((a[i]+a[j]) in a) or ((a[j]+a[k]) in a) or ((a[i]+a[k]) in a)):
				segment = True
		if(triangle == True):
			break
	if(triangle == True):
		break
if(triangle == True):
	print("TRIANGLE")
elif(segment == True):
	print("SEGMENT")
else:
	print("IMPOSSIBLE")

