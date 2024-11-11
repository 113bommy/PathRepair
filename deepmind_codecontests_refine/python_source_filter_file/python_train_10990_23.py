m,d=map(int,input().split())
l1=[1,3,5,7,8,9,12]
l2=[4,6,11]
if m==2 and d==1:
	print(4)
elif m!=2 and d==7:
	print(6)
elif m in l1 and (d==6  or d==7):
	print(6)
else:
	print(5)