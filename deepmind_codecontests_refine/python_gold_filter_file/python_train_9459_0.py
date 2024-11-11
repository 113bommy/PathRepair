from collections import Counter
n=int(input())
a=[int(input()) for i in range(n)]
b=Counter(a[::2])
a.sort()
c=Counter(a[::2])

ans=0
for i in b:
	if i in c:
		ans+=abs(b[i]-c[i])
	else:
		ans+=b[i]
print(ans)