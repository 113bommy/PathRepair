haypiles = []
days = []
a = []
testNum=int(input())
for i in range(testNum):
	line2 = input().split()
	haypiles.append(int(line2[0]))
	days.append(int(line2[1]))
	line3 = input().split()
	for j in range(haypiles[i]):
		line3[j] = int(line3[j])
	a.append(line3)

#input taken

for t in range(testNum):
	if haypiles[t] == 1:
		print(a[t][0])
		continue
	while(days[t]>0):
		breakDone = False
		i = 0
		while True:
			if a[t][i+1] > 0:
				a[t][i+1]-=1;
				a[t][i]+=1;
				i=0
				days[t]-=1
				breakDone = True
				break
			i+=1
			if i >= haypiles[t]-1:
				break
		if not(breakDone):
			days[t]=0
	print(a[t][0])
