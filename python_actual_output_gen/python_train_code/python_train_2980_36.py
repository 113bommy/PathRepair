a,b,c = map(int,input().split())
v =[1]
for i in range(1,min(b,c)):
	v.append(2*i)
for i in range(a-(len(v))):
	v.append(1)
x =[1]
for i in range(1,max(b,c)):
	x.append(2**i)
for i in range(a-(len(x))):
	x.append(max(x))
print(sum(v),sum(x))

