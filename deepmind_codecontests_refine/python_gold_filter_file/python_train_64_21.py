n = int(input())

pos = list(map(int,input().split()))

frnd2 = 1000000
frnd1 = 1

t = 0
extreme_left = pos[0]
extreme_right = pos[n-1]



if extreme_left<=frnd2//2 and extreme_right>frnd2//2:
	for i in range(n-1,0,-1):
		if pos[i]>frnd2//2 and pos[i-1]<=frnd2//2:
			t=  (frnd2-pos[i]),(pos[i-1]-1)
			print(max(t))
			exit()
else:
	print(min(extreme_right -frnd1,frnd2- extreme_left))
