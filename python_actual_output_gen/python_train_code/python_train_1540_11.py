n,c=map(int,input().split())
p=list(map(int,input().split()))
t=list(map(int,input().split()))
l=0
r=0
x=0
for i in range(n):
	x+=t[i]
	l+=max(0,p[i]-(c*x))
y=0
for j in range(n-1,-1,-1):
	y+=t[i]
	r+=max(0,p[j]-(c*y))
if(l>r):
	print("Limak")
elif(r>l):
	print("Radewoosh")
else:
	print("tie")