n, m = map(int, input().split())
s, count, a = '', 0, 'face'
p1, p2, p3, p4 = 0, 1, m, m+1
for _ in range(n):
	s += input()

if n<2 or m<2:
	print(count)
else:
	while 1:
		x = ''
		x += s[p1]+s[p2]+s[p3]+s[p4]
		if sorted(x)==sorted(a):
			count+=1
		if p4 == n*m-1:
			break
		if p2 == m-1:
			p1+=2; p2+=2; p3+=2; p4+=2
		else:
			p1+=1; p2+=1; p3+=1; p4+=1
	print(count)