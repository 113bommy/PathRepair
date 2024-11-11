use = input()

total = 0
p = 0
p1 = len(use) - 1
while p != p1:
	if use[p] == use[p1]:
		p += 1
		p1 -= 1
	elif use[p] == "x":
		p += 1
		total += 1
	elif use[p1] == "x":
		p1 -= 1
		total += 1
	else:
		total = -1
		break
print(total)
