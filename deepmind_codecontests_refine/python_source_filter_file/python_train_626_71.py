a,b,c="1 1 1".split()
n=0
for i in range(int(a),int(b)+1):
	if int(c)%i ==0:
		n+=1

print(n)