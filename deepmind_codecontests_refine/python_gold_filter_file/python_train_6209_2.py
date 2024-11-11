s=[str(i) for i in input().split(' ')]
a,b=s[0],s[1]
w=a[0]
for i in range(1,len(a)):
	if b[0]>a[i]:
		w+=a[i]
	else:
		break
print(w+b[0])
