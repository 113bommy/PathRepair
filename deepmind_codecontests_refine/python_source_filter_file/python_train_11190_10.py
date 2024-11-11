base, massa = map(int, input().split())
for i in range(101):
	if abs(massa - base**i) < massa:
		massa = abs(massa - base**i)

if massa == 0:
	print("YES")
else:
	print("NO")