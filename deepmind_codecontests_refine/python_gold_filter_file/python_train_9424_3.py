n = int(input())
a = [int(i) for i in input().split()]
d = {}
for i in a:
	d[i] = d.setdefault(i,0)+1
x = len(d)-1
b = sorted([i for i in d],key = lambda x:d[x])
ans = 0
for i in range(len(b)):
	if b[i] in d:
		ans += x*d[b[i]]
		t = d[b[i]]
		for j in range(i,len(b)):
			d[b[j]] -= t
			if d[b[j]] <= 0:
				d.pop(b[j])
	x -= 1
print(ans)