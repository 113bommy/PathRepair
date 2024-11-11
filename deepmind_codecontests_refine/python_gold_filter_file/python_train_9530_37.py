n = int(input())
flag = False
for i in range(n):
	a = list(input().split())
	a[1] = int(a[1])
	a[2] = int(a[2])
	if(a[1]>=2400 and a[2]>a[1]):
		flag = True
		break
if flag == True:
	print("YES")
else:
	print("NO")