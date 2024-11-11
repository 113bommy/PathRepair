m,n=map(int,input().split())
c=0
d=0
x=0
y=0
p=list(map(int,input().split()))
q=list(map(int,input().split()))
for i in range(m):
	x+=q[i]
	y+=q[m-i-1]
	c+=max(0,p[i]-n*x)
	d+=max(0,p[m-1-i]-n*y)
if(c>d):
	print("Limax")
elif(d>c):
	print("Radewoosh")
else:
	print("Tie")