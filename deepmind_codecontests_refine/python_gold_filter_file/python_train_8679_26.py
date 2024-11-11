
n = int(input())
a = list(map(int,input().split()))

d = [0]*3005
for i in a:
	d[i-1] = 1
for i in range(3002):
	if d[i]==0:
		print (i+1)
		break