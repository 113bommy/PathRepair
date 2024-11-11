# import sys
# sys.stdin=open("test11.in","r")
# sys.stdout=open("test11.out","w")

n,c=map(int,input().split())

p=list(map(int,input().split()))

t=list(map(int,input().split()))
l=0
r=0
e=0
y=0
for i in range(n):
	e+=t[i]
	if((p[i]-c*e)>0):
		l+=(p[i]-c*e)
	else:
		l+=0

for i in range(n-1,0,-1):
	y+=t[i]
	if((p[i]-c*y)>0):
		r+=(p[i]-c*y)
	else:
		r+=0
if(l>r):
	print("Limak")
elif(l<r):
	print("Radewoosh")
else:
	print("Tie")

