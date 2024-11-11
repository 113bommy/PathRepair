n,p = input().split()
d = n[0]

for i in range(1,len(n)):
	if n[i]<p[0]:
		d+=n[i]
	else:
		break

print(d+p[0])
	