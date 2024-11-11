x = int(input())
for i in range(x):
	t = (input())
	r1 = int(t)
	i = 1
	while True:
		t1 = pow(2,i)
		if r1%t1 == r1:
			r = i - 1
			break 
		i = i + 1
	print(int(r1*(r1+1)/2)-2*pow(2,r+1)+2)