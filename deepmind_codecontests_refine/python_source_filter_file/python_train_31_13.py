
n , x   , y =map(int,input().strip().split())  

requi   =      ((x)/n)*100

if requi < y:
	for c in range(0, 10**4):
		requi = ((x+ c)/n)*100
		if requi>=y:
			print(c)
			break
else:
	print(0)