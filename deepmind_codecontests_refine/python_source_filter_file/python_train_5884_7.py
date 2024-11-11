a,b = map(int, input().split())
n=0
for i in range(1,64):
	for j in range(64):
		f='1'*i+'0'+'1'*j
		if a<=int(f,2)<=b:
			print(f)
			n+=1
print(n)