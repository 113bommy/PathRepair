k=int(input())
l=list(map(int,input().split()))
l.sort()
l.reverse()
# print(l)
x=0
y=[]
if k == 0:
	print("0")
elif k>0:
	for i in l:
		x+=i
		y.append(i)
		if x >= k :
			print(len(y))
			break
		if len(y)==12 and x<k:
			print("-1")