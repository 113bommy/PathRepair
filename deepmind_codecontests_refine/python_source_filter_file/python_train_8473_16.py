n=int(input())
a=list(map(int,input().split()))

d={}
for i in range(8):
	d[i]=0

for i in a:
	d[i]+=1

if d[5] or d[7]:
	print(-1)
	exit()

if d[1]!=n//3:
	print(-1)
	exit()

n24=0
n36=0
n26=0

if d[2] and d[4]:
	n24+=d[4]
	d[2]-=d[4]
	d[4]=0
	if d[2]<0:
#		print("Here2")
		print(-1)
		exit()

if d[2] and d[6]:
	n26+=d[2]
#	print(d[2])
	d[6]-=d[2]
	d[2]=0
	if d[6]<0:
#		print("Here3")
		print(-1)
		exit()

if d[3] and d[6]:
	n36+=d[6]
	d[3]-=d[6]
	d[6]=0
	if d[3]<0:
#		print("Here4")
		print(-1)
		exit()

if d[2] or d[4] or d[3] or d[6]:
#	print("Here1")
	print(-1)
	exit()

for i in range(n24):
	print(1,2,4)
for i in range(n36):
	print(1,3,6)
for i in range(n26):
	print(1,3,6)
