t = input()
d = set({"A","H","I","M","O","T","U","V","W","X","Y"})
for i in t:
	if i not in d:
		print(-1)
		exit()
if t == t[::-1]:
	print("YES")
else:
	print("NO")