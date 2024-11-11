
s = input()

t = len(s)

i = 0
c = 0
s1 = ""
r = 0
ans = 0
while i < t-4:

	s1 = s[i] + s[i+1] + s[i+2] + s[i+3]
	# print(s1)
	if s1 == "bear":
		a = (i-r+1)*(t-i-3)
		ans = ans + a
		r = i+1
	i = i + 1

print(ans)