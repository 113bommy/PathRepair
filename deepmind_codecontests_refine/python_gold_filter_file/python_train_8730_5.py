x=[0]*51
for a in range(10):
	for b in range(10):
		for c in range(10):
			for d in range(10):
				x[a+b+c+d]+=1
while True:
	try:
		print(x[int(input())])
	except:
		break