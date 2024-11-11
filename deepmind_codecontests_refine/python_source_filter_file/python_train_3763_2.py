def gcd(a,b):
	a,b= abs(a),abs(b)
	while b > 0:
		a,b = b, a %b
	return a
kk=lambda:map(int,input().split())
ll=lambda:list(kk())
n,a,b,c,d,m = int(input()), ll(),ll(),0,{0:0},0
for i in range(n):
	if a[i] == 0:
		if b[i] == 0: c+=1
	else:
		if b == 0: 
			d[0] +=1
			if d[0] > m: m=d[0]
		else:
			g = gcd(a[i],b[i])
			t =(abs(a[i]//g), abs(b[i]//g), (int(a[i]<0)+int(b[i]<0))%2)
			if t not in d: d[t] = 0
			d[t] +=1
			if d[t] > m: m = d[t]
print(m+c)