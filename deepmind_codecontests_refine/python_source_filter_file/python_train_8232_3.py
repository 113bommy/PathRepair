pocBudov, pocPosch, minPohyb, maxPohyb, pocOtazok = list(map(int, input().split()))
odpovede = []
for i in range(pocOtazok):
	otazka = list(map(int, input().split()))
	od, do = otazka[:2], otazka[2:]

	if od[1] >= minPohyb and od[1] <= maxPohyb:
		odpovede.append(abs(do[0]-od[0])+abs(do[1]-od[1]))
		
	elif od[0] == do[0]:
		odpovede.append(abs(od[1]-do[1]))
		
	else:
		if do[1] > maxPohyb:
			x = maxPohyb
		else:
			x = minPohyb
		odpovede.append(abs(do[0]-od[0]) + abs(min(maxPohyb-od[1], od[1]-minPohyb)) + abs(x-do[1])) 
	
	
for i in odpovede:
	print(i)
# 0 - budova
# 1 - poschodie