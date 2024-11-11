n,a,b,c,d = map(int, input().split())
s = input()
if s[a:c].count("##")!=0 or s[b:d].count("##")!=0:
	print("No")
	exit()

if c > d:
	if s[b:d].count("...") == 0:
		print("No")
		exit()
print("Yes")