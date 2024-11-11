# your code goes here
n = int(input())
for i in range(n):
	res = 0
	text = input().split()
	nj = int(text[2])
	rj = int(text[0])
	lj = int(text[1])
	if(rj == lj and nj%2 == 0):
		print(0)
	elif(rj == lj and nj%2 != 0):
		print(1)
	else:
		if(nj%2 == 0):
			res = int(nj/2)*rj - int(nj/2)*lj
		else:
			res = (int(nj/2)+1)*rj - (int(nj/2))*lj
		
		print(int(res))