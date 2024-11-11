k = int(input())
s = "aeiou"
for i in range (5, k+1):
	if k%i > 0 : continue
	j = k//i
	if i < 5 or j < 5: continue
	ans = ""
	for x in range(0,i):
		for y in range (0,j): ans+=s[(i+j)%5]
	print(ans)
	break
else: print(-1)