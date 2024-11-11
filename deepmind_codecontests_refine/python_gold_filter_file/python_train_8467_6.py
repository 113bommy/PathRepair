n = int(input())
f0 = 0
f1 = 1
while(f1 < n):
	f2 = f1
	f1 = f1 + f0
	f0 = f2
a = f0
f0 = 0
f1 = 1
while((a+f1) < n):
	f2 = f1
	f1 = f1 + f0
	f0 = f2
b = f0
f0 = 0
f1 = 1
while((a+b+f1) < n):
	f2 = f1
	f1 = f1 + f0
	f0 = f2
c = f1
if(n == 0):
 c = 0
if(a + b + c == n):
	if(n == 2):
		print(str(1) + " " + str(1) + " " + str(0))
	elif(n == 3):
		print(str(1) + " " + str(1) + " " + str(1))
	else:
		print(str(c) + " " + str(b) + " " + str(a))
else:
	print("I'm too stupid to solve this problem")