nStr = input()
n = int(nStr)

pointStr = input()
pointLine = pointStr.split()

pMax = 0
pMin = 10001

amazing = -2

for i in range(n):
	point = int(pointLine[i])
	
	if point>pMax:
		amazing = amazing+1
		pMax = point
		
	if point<pMin:
		amazing = amazing+1
		pMin = point
		
print(amazing)