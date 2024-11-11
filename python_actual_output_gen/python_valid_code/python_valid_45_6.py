lines,P1,P2,P3,T1,T2 = list(map(int, input().split(" ")))
work,power = [],0
for line in range(lines):
	work.append((list(map(int, input().split(" ")))))
for i in range(len(work)-1):
	power = P1*(work[i][1] - work[i][0])
	time_interval = work[i+1][0] - work[i][1]
	if T1 < time_interval:
		power +=P1*T1
		if T1+T2 < time_interval:
			power +=P2*T2
			power +=P3*(time_interval-T1-T2)
		else: power+= P2*(time_interval-T1)
	else: power +=P1*time_interval
power +=P1*(work[-1][1] - work[-1][0])
print(power)