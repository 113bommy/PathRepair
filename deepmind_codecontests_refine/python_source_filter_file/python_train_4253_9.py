s = input()
 
ans = 0
p = 0
q = len(s) - 1
while p < 1:
	if s[p] == s[q]:
		p += 1
		q -= 1
	elif s[p] == "x":
		p += 1
		ans += 1
	elif s[q] == "x":
		q -= 1
		ans += 1
	else:
		ans = -1
		break
print(ans)