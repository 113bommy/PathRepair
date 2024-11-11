s=0
w,h,k=map(int,input().split())
for x in range(1,k+1):
	w=w-4*(x-1)
	h=h-4*(x-1)
	s+=2*w+2*(h-2)
print(s)