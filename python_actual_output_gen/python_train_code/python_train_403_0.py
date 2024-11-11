(n,m) = tuple(map(int, input().split(" ")))
x = list(map(int, input().split(" ")))
nib = 0
ans = []
cou = 0;
for i in x:
	nib+=i
	if (nib<m):
		ans.append(nib//m)
	else:
		ans.append(nib//m)
		nib-=(nib//m)
print (*ans)