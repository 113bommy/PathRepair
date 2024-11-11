n = int(input())
a,b,c,d = 0,0,0,0
s = []

for i in range(n):
	h = input()
	s.append(h)



for i in range(n):
	for j in range(n):
		if s[j][i]=="C":
			c+=1
		if s[i][j]=="C":
			d+=1

	a+= sum(range(c))
	b+= sum(range(d))	
	c,d=0,0
print(a,b)