n = int(input())
xa, bx, bxa = 0, 0, 0
ans = 0
for _ in range(n):
	s = input()
	for i in range(len(s)-1):
		if s[i] == "A" and s[i+1] == "B":
			ans += 1
	if s[0] == "B":
		if s[-1] == "A":
			bxa += 1
		else:
			bx += 1
	elif s[-1] == "A":
		xa += 1

if xa == bx:
	if xa == 0:
		print(ans+bxa-1)
	else:
		print(ans+xa+bxa)
else:
	print(ans+bxa+min(xa, bx))