n,m = map(int,input().split())

d = {}

for i in range(m):
	x,y = input().split()
	d[x] = y

s = list(input().split())
p = ''

for i in s:
	if(len(i) < len(d[i])):
		p += i + ' '
	else:
		p += d[i] + ' '

print(p)