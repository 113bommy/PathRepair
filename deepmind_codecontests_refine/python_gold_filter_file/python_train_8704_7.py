s=input()
if str(int(s[::-1])) == str(int(s[::-1]))[::-1]:
	print("YES")
else:
	print("NO")