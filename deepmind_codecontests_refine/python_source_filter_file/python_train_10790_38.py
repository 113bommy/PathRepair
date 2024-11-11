l,r,a=map(int,input().split())
if l+a<=1:
	print(0)
if l+r==0 and l+a>1:
	print(2*a//2)		
if abs(l-r)>=a and l+a!=0:
	print(2*(min(l,r)+a))
if abs(l-r)<a and l+r!=0:
	print(2*(max(l,r)+abs(a-abs(l-r))//2))	