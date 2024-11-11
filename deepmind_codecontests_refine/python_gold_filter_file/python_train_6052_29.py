import sys;input = sys.stdin.readline
s=input()
v=0
h=0
for i in s:
	if i=='0':
		if v%2==0:
			print(1,1)
			v+=1
		else:
			print(3,1)
			v+=1
	elif i=='1':
		print((h%4)+1,3)
		h+=1		

