def l(s1, s2):
	return len(list(i for i in range(len(s1)) if s1[i] != s2[i]))

c = int(input())

if c == 12:
	h = list(range(1, 13))
else:
	h = list(range(0, 23))


s = input()
min_s = ""
min_l = 100

for x in h:
	for y in range(60):
		new_s = "{0:02}:{1:02}".format(x,y)
		if l(s, new_s) < min_l:
			min_l = l(s, new_s)
			min_s = new_s

print(min_s)