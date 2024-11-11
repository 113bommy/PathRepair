t = int(input())


for _ in range(t):
	n,X = [int(x) for x in input().split()]
	deg=0
	for _ in range(n-1):
		x,y = [int(x) for x in input().split()]
		if x==X or y==X:
			deg+=1
	
	if deg<=1:
		winner = "Ayush"
	elif (n-3)%2==0:
		winner = "Ashish"
	elif (n-1-deg)%2==1:
		winner = "Ayush"
	print(winner)

	#holo