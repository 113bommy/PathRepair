
t=int(input())

while(t):
	b,p,f=list(map(int,input().split()))
	h,c=list(map(int,input().split()))
	total_buns=b//2
	total_burger=p+f
	while True:
		if total_buns>=total_burger:
			if f<0:
				p=p+f
				f=0
			else:
				f=f+p
				p=0
			profit=c*f+h*p
			break
		else:
			if h>c:
				f-=1
			else:
				p-=1

		total_burger=f+p

	print(profit)
	t-=1


# 2
# 100 51 51
# 100 99
# 99 51 51
# 100 99
