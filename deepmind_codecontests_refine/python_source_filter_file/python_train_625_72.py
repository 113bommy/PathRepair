a,b,c=input().split()
n=0
for i in range(int(a),int(b)):
	if int(c)%i ==0:
		n+=1

print(n)