n = int(input())
pwd = ['/']

for i in range(0,n):
	command = str(input())
	
	if command == 'pwd':
		print(''.join(pwd))
	else:

		path = list(filter(None, command[3:].split('/')))
		#print(path)
		
		if command[3] == '/':
			pwd = ['/']
			
		for dir in path:
			if dir == '..':
				if pwd[-1]=='/':
					pwd = pwd[:-2]
				else:
					pwd = pwd[:-1]
				
			else:
				pwd.append(dir+'/')