n = int(input())
v = list(map(int,input().split()))

ok = True
while ok == True:
	ok = False
	for i in range(len(v)):
		if i != (len(v)-1):
			if v[i] > v[i+1]:
				print ("{0} {1}".format(i+1, i+2))
				v[i], v[i+1] = v[i+1], v[i]
				ok = True
print(v)
