S = input()

c, f = False, False
for s in S:
	if s == "C":
		c = True
	if s == "F" and c:
		f = True
print(["Yes", "No"][not(all([c, f]))])
