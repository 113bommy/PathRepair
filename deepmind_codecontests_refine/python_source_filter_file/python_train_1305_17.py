a,b,c=map(int,input().split())
if b==a and c==0:
	print("YES")
elif b!=a and c==0:
	print("NO")
elif (b-a)%c==0 and ((a<b and c>0) or (a>b and c<0)) :
	print("YES")
else:
	print("NO")