n = int(input())
for i in range(n):
	s = input()
	k = len(s)
	if s[k-2:k] == "po":
		print("FILIPINO")
	elif s[k-5:k] == "mnida":
		print("KOREAN")
	else:
		print("JAPENESE")