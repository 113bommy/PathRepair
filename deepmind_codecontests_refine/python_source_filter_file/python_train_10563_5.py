n,m = map(int,input().split())
l,k,f = [],[],[]
for i in range(m):
	b = list(input().split())
	l.append(b[0])
	k.append(b[1])
g = list(input().split())
for j in range(n):
	t = l.index(g[j])
	if len(l[t])<len(k[t]):f.append(l[t])
	else:f.append(k[t])
print(*f)