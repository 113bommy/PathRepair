n=int(input())
x=list(map(int,input().split()))
l=[]
t=[]
v=[]
a=0
b=0
c=0
for i in range(1,n+1):
	if i%3==1:
		l.append(x[i-1])
		
	elif i%3==2:
		t.append(x[i-1])
	else:
		v.append(x[i-1])
a=sum(l)
b=sum(t)
c=sum(v)

if a>b and a>c:
	print("chest")
elif b>a and b>a:
	print("biceps")
else:
	print("back")
