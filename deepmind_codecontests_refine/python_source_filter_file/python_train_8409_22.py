X = int(input())

r = X

while(True):
	for i in range(2, r):
		if r%i == 0:
			r += 1
			continue      
	else:
		break
print(r)