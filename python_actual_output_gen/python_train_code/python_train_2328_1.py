a=input()
bumpers = input()
counter = 0

for i in range(len(bumpers)):
	if bumpers[i]=='<':
		counter+=1
	else:
		break

for i in range(1,len(a)+1):
	if bumpers[-i]=='>':
		counter+=1
	else:
		break
		
print(counter)