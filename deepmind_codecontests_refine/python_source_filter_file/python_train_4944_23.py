import sys
from datetime import datetime

n = int(input()) #количество карт

k1 = input().split()
k2 = input().split()

k1 = [int(x) for x in k1]
k2 = [int(x) for x in k2]
k1.pop(0)
k2.pop(0)





iteration = 0
while (len(k1) !=0  and len(k2) !=0 ):
	karta_1 = k1[0]
	karta_2 = k2[0]
	if(karta_2 > karta_1):
		k1.pop(0)
		k2.pop(0)
		k2.append(karta_1)
		k2.append(karta_2)
		
	if(karta_2 < karta_1):
		k2.pop(0)
		k1.pop(0)
		
		k1.append(karta_2)
		k1.append(karta_1)

	
	iteration = iteration + 1
	if(iteration > 100):
		break
		



if(iteration > 100):
	print(-1)
	sys.exit()
if(len(k2) != 0):
	print(iteration, 2)
if(len(k1) !=0):
	print(iteration, 1)


