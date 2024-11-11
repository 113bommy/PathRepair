a,b,c,d=map(int,input().split())
m=max(((3//10)*a),(a-(a*c)//250))
v=max(((3//10)*b),(b-(b*d)//250))
if m>v:
	print('Misha')
elif m<v:
	print('Vasya')
else:
	print('Tie')