


n = int(input())
seq = list(map(int,input().split()))
seq.sort()


cont = 0
for i in seq:
	if i == 1:
		cont += 1

if(n == 1):
	if seq[0] == 1:
		print('2')
	else:
		print('1')
elif(cont >= n-1):
	res = ""
	for i in range(n-1):
		res += "1 "
	if(seq[n-1] == 2):
		res += "1"
	else:
		res += "2"
	print (res)
else:
	res = "1"
	for i in seq[:-1]:
		res += " " + str(i)	
	print(res)






















