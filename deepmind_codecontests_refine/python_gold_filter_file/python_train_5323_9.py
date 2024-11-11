n = int(input())

ind = 0
maxind = 0
while (n-ind*7>=0):
	lef = n-ind*7
	if lef%4==0:
		maxind = ind
	ind+=1

if (n-maxind*7)%4 != 0:
	print(-1)
else:
	ans = []
	for i in range(maxind):
		ans.append(7)
	rem = n-maxind*7
	ind4 = rem//4
	for i in range(ind4):
		ans.append(4)
	l = len(ans)
	for i in range(l-1,-1,-1):
		print(ans[i],end="")
	print()