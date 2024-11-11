s1 = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
n = int(input())
s = input()
a = [[0,0] for i in range(n)]
for i in range(n):
	# print(i)
	x = 0
	y = 0
	if(s[i] == 'U'):
		y = 1
	elif(s[i] == 'D'):
		y = -1
	elif(s[i] == 'L'):
		x = -1
	elif(s[i] == 'R'):
		x = 1
	# print(max(i-1,0))
	a[i][0] = a[max(i-1,0)][0] + x
	a[i][1] = a[max(i-1,0)][1] + y
high = 1000000000000000
low = 0
c = 0
while(low<high):
	mid = (high+low)//2
	p = 0
	p1 = 0
	if(mid%n != 0):
		p = a[mid%n-1][0]
		p1 = a[mid%n-1][1]
	x1 = d[0] - (s1[0] + a[n-1][0]*(mid//n) + p)
	y1 = d[1] - (s1[1] + a[n-1][1]*(mid//n) + p1)
	# print(x1,y1,mid)
	# if(mid == 2):
	# 	print(s1[1],a[n-1][1]*(mid//n),a[mid%n][1])
	# if((x1+y1)==mid):
	# 	low = mid
	# 	c = 1
	# 	break
	if((abs(x1)+abs(y1))<=mid):
		# print(mid)
		c = 1
		high = mid
	else:
		low = mid + 1
if(c == 0):
	print(-1)
else:
	print(low)
