import math
tu=int(input())
for tu in range(tu):
	fg=input().split(' ')
	asp=int(fg[1])
	bsp=int(fg[0])
	a=min(asp,bsp)
	b=max(asp,bsp)
	d=b-a
	k=math.ceil(((math.sqrt(1+8*d))-1)/2)
	for h in range(4):
		if (d+((k*(k+1))//2))%2==0:
			print(k)
			break
		k+=1


