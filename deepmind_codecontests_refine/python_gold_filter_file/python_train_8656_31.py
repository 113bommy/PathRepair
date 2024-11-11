a = int(input())

p = 0
for i in range(a):
	p = 0
	b = int(input())
	c = input()
	if(c[0]=="8" and b>=11):
		print("YES")
	else:
		while(len(c)>11):
			c = c[1:]
			if(c[0]=="8" and b>=11):
				print("YES")
				p = 1
				break
		if(p==0):
			print("NO")