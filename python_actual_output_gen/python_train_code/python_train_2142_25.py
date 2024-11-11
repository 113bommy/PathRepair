n,p = input().split()
d = n[0]

for i in range(1,len(n)):
	if n[i]<n[i+1]:
		d+=n[i]
	else:
		break

print(d+p[0])
	