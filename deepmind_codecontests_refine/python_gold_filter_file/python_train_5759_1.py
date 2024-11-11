def ispal(n,l):
	for i in range(0,l//2):
		if n[i] != n[l-i-1]:
			return False
	return True
			
for _ in range(int(input())):
	n = input()
	l = len(n)

	f = n+"a"
	s = "a"+n
	if not ispal(f,len(f)):
		print("YES")
		print(f)
	elif not ispal(s,len(s)):
		print("YES")
		print(s)
	else:
		print("NO")