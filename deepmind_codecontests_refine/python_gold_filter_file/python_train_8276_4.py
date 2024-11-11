
h,m=map(int,input().split(":"))
a=int(input())
if a+m>=60:
	h+=(a+m)//60
	m=(a+m)%60
else:
	m+=a

if h>=24:
	h=h%24
h=str(h)
m=str(m)
if len(h)==1:
	h="0"+h
if len(m)==1:
	m="0"+m
print(":".join([h,m]))