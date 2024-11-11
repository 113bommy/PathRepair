n = int(input())
arr = list(map(int,input().split()))

li = []
cost = []
for i in range(n):
	s = input()
	x  = s[::-1]
	li.append([s,x])
	cost.append([0,arr[i]])

md = 10**10

flag = 0 
for i in range(1,n):
	if li[i][0]>=li[i-1][0]:
		x = cost[i-1][0]
	else:
		x = md

	if li[i][0]>=li[i-1][1]:
		y = cost[i-1][1]
	else:
		y = md 
	if li[i][1]>=li[i-1][0]:
		m=cost[i-1][0]
	else:
		m = md 
	if li[i][1]>=li[i-1][1]:
		k = cost[i-1][1]
	else:
		k = md 

	if min(x,y)==md and min(m,k)==md:
		flag = 1
		break
	cost[i][0]+=min(x,y)
	cost[i][1]+=min(m,k)
if flag :
	print(-1)
else:
	print(min(cost[n-1]))
