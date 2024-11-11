n=int(input())

a=list(map(int,input().split()))

t=0
o=0

for i in a:
	if i==1:
		o+=1
	else:
		t+=1

if o<=t:
	print(o)
else:
	print(o+(o-t)//3)