v=list(map(int,input().split()))
def funk(a):
	if ((a[0]==a[2]+a[4])and(a[1]+a[3]==a[0])and(a[3]==a[5])):
		print(a[0])
		for i in range(a[1]):
			print('A'*a[0])
		for i in range(a[3]):
			print('B'*a[2]+'C'*a[4])
	elif ((a[0]==a[2]==a[4])and(a[1]+a[3]+a[5]==a[0])):
		print(a[0])
		for i in range(a[1]):
			print('A'*a[0])
		for i in range(a[3]):
			print('B'*a[2])
		for i in range(a[5]):
			print('C'*a[4])
	elif ((a[0]+a[2]+a[4]==a[1])and(a[1]==a[3]==a[5])):
		print(a[1])
		for i in range(a[1]):
			print('A'*a[0]+'B'*a[2]+'C'*a[4])
	elif ((a[0]+a[2]==a[4])and(a[1]==a[3])and(a[1]+a[5]==a[4])):
		print(a[4])
		for i in range(a[1]):
			print('A'*a[0]+'B'*a[2])
		for i in range(a[5]):
			print('C'*a[4])
	elif ((a[0]+a[2]==a[1])and(a[2]==a[4])and(a[3]+a[5]==a[1])):
		print(a[1])
		for i in range(a[3]):
			print('A'*a[0]+'B'*a[2])
		for i in range(a[5]):
			print('A'*a[0]+'C'*a[4])
	elif ((a[0]+a[2]==a[3])and(a[0]==a[4])and(a[1]+a[5]==a[3])):
		print(a[3])
		for i in range(a[1]):
			print('A'*a[0]+'B'*a[2])
		for i in range(a[5]):
			print('C'*a[4]+'B'*a[2])
	else:
		#~ print('-1')
		return 0
	return 1
s=0
for i in range(2):
	v[0],v[1]=v[1],v[0]
	for i1 in range(2):
		v[2],v[3]=v[3],v[2]
		for i2 in range(2):
			v[4],v[5]=v[5],v[4]
			if s==0:
				s=funk(v)
			if s:break
if s==0:
	print('-1')