n=int(input())
ct1=0
ct2=0
for i in range(n):
	a,b=map(int, input().split())
	if b>0:
		ct1+=1
	else:
		ct2+=1
if ct1<2 or ct2<2:
	print("Yes")
else:
	print("No")