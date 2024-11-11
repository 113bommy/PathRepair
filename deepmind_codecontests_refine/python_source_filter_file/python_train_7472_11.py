N = int(input())
left = []
right = []
last = None
for i in range(N):
	s = input()
	l = len(s)
	r_needed = 0
	l_needed = 0
	for j in range(l):
		if s[j] == "(":
			r_needed += 1
		elif s[j] == ")" and r_needed > 0:
			r_needed -= 1

		if s[l-1 - j] == ")":
			l_needed += 1
		elif s[l-1 - j] == "(" and l_needed > 0:
			l_needed -= 1
	if r_needed < l_needed:
		right.append((-r_needed, l_needed))
	else:
		left.append((l_needed, -r_needed))

left.sort()
right.sort()
rest_l = 0
for l in left:
	l_needed = l[0]
	r_needed = -l[1]
	if rest_l < l_needed:
		print("No")
		exit()
	rest_l += r_needed - l_needed
for r in right:
	l_needed = r[1]
	r_needed = -r[0]
	if rest_l < l_needed:
		print("No")
		exit()
	rest_l -= l_needed
	rest_l += r_needed
if rest_l != 0:
	print("No")
else:
	print("Yes")