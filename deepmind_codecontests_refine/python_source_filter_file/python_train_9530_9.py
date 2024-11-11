t=int(input())
for i in range(t):
	a,b,c=input().split()
	if int(b)>=2400 and int(c)>2400:
		print("YES")
		break
	elif i==t-1:
		print("NO")