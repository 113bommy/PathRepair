#1281A in codeforces
t = int(input())
for _ in range(t):
	s = input()
	last = s[-2:]
	if last == "po":
		print("FILIPINO")
	else:
		last = s[-4:]
		if last == "desu" or last == "masu":
			print("JAPANESE")
		else:
			last = last[-5:]
			if last == "mnida":
				print("KOREAN")