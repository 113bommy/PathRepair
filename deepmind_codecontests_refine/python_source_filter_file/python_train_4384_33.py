a,b,c=map(int,input().split())
count=0
for i in range(c):
	count+=2*(a-4*i)+2*(b-4*i)-4
	print(count)