ac = bc = oc = abc = 0
while 1:
	try: n, bt = input().split(",")
	except: break
	if bt == "A": ac += 1
	elif bt == "B": bc += 1
	elif bt == "O": oc += 1
	elif bt == "AB": abc +=1
print(ac)
print(bc)
print(abc)
print(oc)
