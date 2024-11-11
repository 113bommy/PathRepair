n,m=map(int,input().split(" "))
o=0
for i in range(n):
	d,s=map(str,input().split(" "))
	if d=="+":
		m+=int(s)
	elif d=="-":
		if (m-int(s))>0:
			m-=int(s)
		else:
			o+=1
print(m,o)