test = int(input())
for i in range(test): 
	l = list(map(int,input().split()))
	
	#Worst Case
	n,x,y = l[0] ,l[1] ,l[2]
	part1 = min(n-x,y-1)
	part2 = min(n-y,x-1)
	w = part1 + part2 + min(y-1-part1,x-1,part2)

	worst = w+1 #including themself

	#Best Case
	part1 = min(y-1,n-x-1)
	part2 = min(x-1,n-y-1)
	part1 = max(part1,0)
	part2 = max(part2,0)
	best = n-(part1+part2+min(n-x-part1,n-y-part2))
	print(best,worst)
