s = input()
new = []
i = 0

if s[0] == "h":
	i += 4
	new.append("http")
else:
	i += 3
	new.append("ftp")

new.append("://")

temp = ""
for i in range(i, len(s)):
	if s[i] == "r" and s[i+1] == "u":
		i += 2
		break

	temp += s[i]

new.append(temp + ".")
new.append("ru")

if i != len(s):
	new[-1] = new[-1] + "/"
	new.append(s[i:])

print("".join(new))