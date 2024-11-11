a = [str(i) for i in input()]

if len(a) > 10:
	print("NO")
	exit()

for bit in range(2 ** (len(a)+1)):
	s = a.copy()

	for i in range(0,len(a)+1):
		if (bit >> i) & 1:
			s.insert(i*2, "A")
			
	if "".join(s) == "AKIHABARA":
		print("YES")
		exit()

print("NO")

	