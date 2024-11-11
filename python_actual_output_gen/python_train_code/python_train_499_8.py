time = input()

hh = int(time[:2])
mm = int(time[3:])

if hh > 12:
	r = int(hh)-12
else:
	r = int(hh)

print(r*30+int(mm)/2,mm*6)