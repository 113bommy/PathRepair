a,b=map(int,input().split())
x=0
for i in range(a,b+1):
	if str(i)[:2]==str(i)[3:5][::-1]:
		x+=1
print(x)