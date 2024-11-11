S = input()

c, f = False, False
for s in S:
	if s == "F":
		c = True
	if s == "F" and c:
		f = True
print(["Yes", "No"][not(all([c, f]))])
