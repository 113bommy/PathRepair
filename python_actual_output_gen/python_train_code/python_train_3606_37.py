n, a, b, c, d = map(int, input().split())
s = input()
if "##" in s[a:max(c,d)]:
	print ("No")
	exit()

if c > d:
	if "..." not in s[max(0,b-2):d]:
		print ("No")
		exit()
print ("Yes")