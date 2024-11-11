n = "".join(input().split(":"))
cnt = 0
def H(time):
	hour = int(time[0])
	minute = int(time[1])
	if minute != 59:
		minute += 1 
	elif minute == 59:
		minute == 0
		hour  += 1
	
	time = "".join([str(hour).zfill(2),str(minute).zfill(2)])
	return time

while n != n[::-1]:
	if n=="2359":
		cnt+=1
		break
	n1 = [n[0:2]]
	n2 = [n[2::]]
	time = n1+n2
	n = H(time)
	cnt+=1

print(cnt)



