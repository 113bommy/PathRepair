x=0
y=1
def gcd(a,b):
	if b==0:return a
	else:return gcd(b,a%b);
def exgcd(a,b):
	if b==0:
		return a
	else:
		d=exgcd(b,a%b)
		global x,y
		t=x
		x=y
		y=t-(a//b)*y
		return d
n,p,w,d=map(int,input().split())
g=gcd(w,d)
if p%g!=0:
	print(-1)
else:
	p=p//g
	w=w//g
	d=d//g
	exgcd(w,d)
	x=x*p
	y=y*p
	x=(x%d+d)%d
	y=(p-w*x)//d
	if y!=0:
		y=(y%w+w)%w
		x=(p-y*d)//w
	if y<0 or x<0 or x+y>n:
		print(-1)
	else:
		print(x,y,n-x-y)