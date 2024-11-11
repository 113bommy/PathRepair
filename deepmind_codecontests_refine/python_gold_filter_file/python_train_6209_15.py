fname, lname = input().split(' ')
login = []
login.append(fname[0])
for i in range(1, len(fname)):
	if ord(fname[i]) < ord(lname[0]):
		login.append(fname[i])
	else:
		break
login.append(lname[0])
print(''.join(login))