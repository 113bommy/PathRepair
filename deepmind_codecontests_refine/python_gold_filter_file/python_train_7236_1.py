x,y=map(int,input().split())

c,v=map(int,input().split())

b,n=map(int,input().split())


if (x==c and c==b) or (y==v and v==n):
	print(1)
	exit()


ans=3

if x==c and (n>=max(y,v) or n<=min(y,v)):ans=2

elif x==b and (v>=max(y,n) or v<=min(y,n)):ans=2

elif c==b and (y>=max(v,n) or y<=min(v,n)):ans=2

elif y==v and (b>=max(x,c) or b<=min(x,c)):ans=2

elif y==n and (c>=max(x,b) or c<=min(x,b)):ans=2

elif v==n and (x>=max(c,b) or x<=min(c,b)):ans=2

print(ans)