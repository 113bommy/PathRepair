a=list(map(int,input().strip().split(" ")))
b=list(map(int,input().strip().split(" ")))
a.append(a[1])
b.append(b[1])
for i in range(20000):
	if a[2]!=b[2]:
		if a[2]<b[2]:
			a[2]+=a[0]
		else:
			b[2]+=b[0]
	else:
		print(a[2])
		break
else:
	print("-1")