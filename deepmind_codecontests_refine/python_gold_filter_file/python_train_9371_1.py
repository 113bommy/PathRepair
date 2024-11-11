import sys
data=list(map(int,input().split()))
order=sys.stdin.readline()
char_list=list(order)
for i in char_list:
	
	if i=='N':
		k=data[0]
		m=data[4]
		data[0]=data[1]
		data[1]=data[5]
		data[4]=k
		data[5]=m
	elif i=='E':
		k=data[0]
		m=data[2]
		data[0]=data[3]
		data[2]=k
		data[3]=data[5]	
		data[5]=m
	elif i=='S':
		k=data[0]
		m=data[1]
		data[0]=data[4]
		data[1]=k
		data[4]=data[5]
		data[5]=m
	elif i=='W':
		k=data[0]
		m=data[3]
		data[0]=data[2]
		data[2]=data[5]
		data[3]=k
		data[5]=m
print(data[0])