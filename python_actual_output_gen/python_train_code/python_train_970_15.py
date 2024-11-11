x=int(input())
h,m=tuple(map(int,input().split()))
count=0
while(1):
	if '7' in str(m) or '7' in str(h):
		print(count)
		break
	m=m-x
	count+=1
	if m<0:
		m=59-m
		h-=1
		if h<0:
			h=23