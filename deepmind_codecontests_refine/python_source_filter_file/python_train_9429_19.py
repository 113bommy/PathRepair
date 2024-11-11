n=int(input())
a=list(map(int,input().split()))
a.sort()

while len(a)>3 and a[-1]>=a[-2]+a[-3]:
	a.pop()
if len(a)<3:
	print("NO")
else:
	print("YES")