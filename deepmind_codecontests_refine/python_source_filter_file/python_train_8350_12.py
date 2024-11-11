t=int(input())
for i in range(t):
	h,m=map(int,input().split())
	h=abs(h-24)
	if(h==1):
		m=abs(m-60)
		print(m)
	if(h==24):
		h=24*60
		print(h-m)
	if(1<h<23):
		h=h-1
		h=h*60
		print(h+abs(m-60))
