a=list(map(int,input().strip().split(" ")))
b=list(map(int,input().strip().split(" ")))
a.append(a[0])
b.append(b[0])
for i in range(20000):
	if a[2]!=b[2]:
		if a[2]<b[2]:
			a[2]+=a[1]
		else:
			b[2]+=b[1]
	else:
		print(a[2])
		break
else:
	print("-1")