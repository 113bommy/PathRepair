n,a,d = int(input()),list(map(int,input().split())),[0 for i in range(100100)]
for x in a:
	d[x] += 1
s,q = sum(a),int(input())
for i in range(q):
	b,c = map(int,input().split())
	s += (c-b)*d[x]
	d[c] += d[b]
	d[b] = 0
	print(s)