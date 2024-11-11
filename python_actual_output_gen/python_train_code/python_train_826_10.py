a,b = map(int,input().split())
d = b
c = b%10
if c % 2!=0 and c!=1:
	print("NO")
else:
	l = []
	if c == 1:
		b = b-1
		b//=10
		l.append(b)
	else:
		b//=2
		l.append(b)
	while b > a:
		if b % 2 != 0 and b%2!=1:
			print("NO")
			exit()
		if b % 10 == 1:
			b-=1
			b//=10
		else:
			b//=2
		l.append(b)
	if b != a:print("NO")
	else:
		print("YES")
		print(len(l)+1)
		s=""
		for i in range(len(l)-1,-1,-1):s+=str(l[i]);s+=" "
		s+=str(d)
		print(s)