case=int(input())
for i in range(case):
	l=int(input())
	data=input()
	data=data.split()
	data=[int(x) for x in data]
	data.sort()
	yo=0
	for i in range(len(data)-1):
		if data[i]==data[i+1]:
			continue
		else:
			yo+=1
	print(yo)