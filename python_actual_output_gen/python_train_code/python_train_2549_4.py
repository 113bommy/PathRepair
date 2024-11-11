A=[]
while True:
	try:
		x=int(input())
		A.append(x)
	except EOFError:
		break

num=[]
for i in range(10):
	num.append((A.count(i),i))

num.sort(reverse=True)
mode_value=num[0][0]
B=[]
for i in num:
	if i[0]==mode_value:
		B.append(i[1])
		
B.sort()
for i in B:
	print(i)