d = {'AC':0, 'WA':0, 'TLE':0, 'RE':0}
for _ in range(int(input())):
	d[input()] += 1
for i in d:
	print(i,'X',d[i])