#/usr/bin/python


import sys

n=int(sys.stdin.readline())
i=0
home=sys.stdin.readline().strip()
A={}
while i < n:
	st = sys.stdin.readline().split('->')
	#print(st[0],st[1][:-1])
	if st[0] in A.keys() :
		A[st[0]].append(st[1][:-1])
	else:
		A[st[0]] = [st[1][:-1]]

	i += 1

B={}
print(A)
for i in A.keys():
	B[i] = 0;

i = home
f = 0
while True:
	try :
		if ( B[i] >= len(A[i])):
			for j in A.keys():
				if B[i] < len(A[j]):
					i = j
					f = 1
					break
			if ( f == 0 ):
				break
		x = A[i][B[i]];
		B[i] += 1
		i = x
	except :
		if ( i == home ):
			i = home+"1"
		break
if ( i == home ):
	print("home")
else:
	print("contest")

