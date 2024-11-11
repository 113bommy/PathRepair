n,m,r=map(int,input().split())
buy=list(map(int,input().split()))
sell=list(map(int,input().split()))
x=(r//min(buy))
left=r-(x*(min(buy)))
y=max(sell)*x
if y>r:
	print(y+left)
else:
	print(r)