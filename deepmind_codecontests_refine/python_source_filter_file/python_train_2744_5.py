n = int(input())
answ = 1
kass = 1
time = []

for i in range(n):
	time.append(input())
time.append('none')

for i in range(n-1):
	if time[i] == time[i+1]:
		kass += 1
	else:
		if kass > answ:
			answ = kass
			kass = 1
print(answ)
