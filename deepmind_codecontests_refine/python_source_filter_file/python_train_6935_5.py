h,m,s,x,y=map(int,input().split())
h=h+m/60+s/3600
m=m/5
s=s/5
l=[h,m,s,x,y]
l.sort()
z=(l.index(x)-l.index(y))
if(z==1 or z==4):
	print("YES")
else:
	print("NO")


    