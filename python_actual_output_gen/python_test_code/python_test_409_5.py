import sys
input=sys.stdin.buffer.readline

x,t,a,b,da,db=map(int,input().split())
isprinted=False
for i in range(t):
	for j in range(t):
		if a-i*da+b-j*db==x:
			print(i,j)
			print("YES")
			isprinted=True
			break
	if isprinted:
		break
#if isprinted==False:
#	print("NO")

if isprinted==False:
	for i in range(t):
		if a-i*da==x:
			print("YES")
			isprinted=True
			break
		if b-i*db==x:
			print("YES")
			isprinted=True
			break
	if isprinted==False:
		if x==0:
			print("YES")
		else:
			print("NO")