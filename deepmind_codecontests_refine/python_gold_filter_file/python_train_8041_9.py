for i in range(int(input())):
	a=int(input())
	b=list(map(int,input().split()))
	r=0
	o,e=0,0
	for j in range(a):
		if b[j]%2==0:
			e+=1
		if b[j]%2==1:
			o+=1
		if j%2!=b[j]%2:
			r+=1
	if a%2==0:
		if e==a//2 and o==a//2 and r%2==0:
			print(r//2)
		else:
			print(-1)
	else:
		if o==a//2 and e==(a+1)//2 and r%2==0:
			print(r//2)
		else:
			print(-1)