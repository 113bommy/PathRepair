
n,d=map(int,input().split())
b=0
v=''
da=1
for i in range(d):
	s=input()
	for i in s:
		b=0
		if i=='0':
			b+=1
			break
		else:
			if i!='0':
				b=0
		# b=0
	v=v+str(b)
print(v)
print (max(map(len, v.split('0'))))