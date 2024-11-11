l, r = input().split()

l = int(l)
r = int(r)

dif = r-l
pairs = (dif+1)/2
cont = 0
if(dif >= pairs):
	print("YES")
	for i in range(l,r,2):
		print(i,i+1)
		cont+=1
		if(cont==pairs):
			break
else:
	print("NO")