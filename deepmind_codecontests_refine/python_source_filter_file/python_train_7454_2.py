# Task2 Codeforces 837b

a,b=input().split()
a=int(a)
b=int(b)

arr=[]
Rflag=Gflag=Bflag=flag=False

for i in range(a):
	arr+=[list(input().strip())]

if a%3==0:
	flag=True
	for i in range(3):
		for j in range(a//3):
			if j==0 and flag==True:
				if arr[(a//3)*i+j].count('R')==b and Rflag==False:
					curr=['R']
					Rflag==True
				elif arr[(a//3)*i+j].count('G')==b and Gflag==False:
					curr=['G']
					Gflag==True
				elif arr[(a//3)*i+j].count('B')==b and Bflag==False:
					curr=['B']
					Bflag==True
				else:
					flag=False
			elif flag==True:
				if arr[(a//3)*i+j]!=curr*b:
					flag=False

if b%3==0 and flag==False:
	arr=tuple(zip(*arr[::-1]))
	Rflag=Gflag=Bflag=False
	a,b=b,a
	flag=True
	for i in range(3):
		for j in range(a//3):
			if j==0 and flag==True:
				if arr[(a//3)*i+j].count('R')==b and Rflag==False:
					curr='R'
					Rflag==True
				elif arr[(a//3)*i+j].count('G')==b and Gflag==False:
					curr='G'
					Gflag==True
				elif arr[(a//3)*i+j].count('B')==b and Bflag==False:
					curr='B'
					Bflag==True
				else:
					flag=False
			elif flag==True:
				if arr[(a//3)*i+j].count(curr)!=b:
					flag=False

if flag and Gflag and Bflag and Rflag:
	print('YES')
else:
	print('NO')