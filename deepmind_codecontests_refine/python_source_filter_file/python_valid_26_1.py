import sys
input=sys.stdin.readline
I = lambda : list(map(int,input().split()))

t,=I()
for _ in range(t):
	s = input().strip()
	one = s[::2]
	two = s[1::2]
	an = 10
	a = b = aq = bq = 0
	taq = one.count("?")
	tbq = two.count("?")

	for i in range(5):
		if one[i]=='1':
			a+=1
		elif one[i]=='?':
			aq+=1
		#print(_,i,(a + aq) , (b + 5 - i))
		if (a + aq) > (b + 5 - i):
			an = 2*i+1
			break
		if (b + bq) > (a + 4 - i):
			an = 2*i+1
			break

		if two[i]=='1':
			b+=1
		elif two[i]=='?':
			bq+=1
		if (a + aq) > (b + 5 - i):
			an = 2*(i+1)
			break
		if (b + bq) > (a + 4 - i):
			an = 2*(i+1)
			break

	print(an)
