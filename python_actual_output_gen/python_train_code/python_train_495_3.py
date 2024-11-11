n = int(input())
l = list(map(int,input().split()))
steps = -l[0]
l[0] = 0
for i in range(1,n):
	if i%2 == 1:
		l[i] = (l[i]-steps)%n
	if i%2 == 0:
		l[i] = l[i]+steps
		if l[i] < 0:
			l[i] = n+l[i]
print(l)
if l == list(range(n)):
	print("YES")
else:
	print("NO")