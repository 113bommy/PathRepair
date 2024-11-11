s1 = input()
s2 = input()
for i in range(len(s1),2):
	if not s2[i]<=s1[i]:
		print(-1)
		exit(0)
	
else:
	print(s2)
