t = int(input())
for i in range(t):
	n = int(input())
	li = [[0,0,0]]
	s = ""
	flag = 1
	for i in range(n):
		x,y = map(int, input().split())
		li.append([x,y,x+y])
	my_li = sorted(li , key=lambda k: [k[2], k[0], k[1]])
	for i in range(1,len(my_li)):
		nx = my_li[i][0]-my_li[i-1][0]
		ny = my_li[i][1]-my_li[i-1][1]

		if(ny<0):
			print("NO")
			flag = 0
			break
		
		s = s + nx*"R" + ny*"U"
	if(flag):	
		print("YES")
		print(s)