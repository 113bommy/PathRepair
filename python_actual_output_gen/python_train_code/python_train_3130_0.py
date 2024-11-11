n = int(input())
a = input()
new = ""
c = 0
m = "0"
for i in a:
	if(i == m):
		c += 1
	else:
		if(m == "0"):
			new += ("0" * (c - 1))
		else:
			new += str(c)
		m = i
		c = 1
if(m == "0"):
	new += ("0" * (c - 1))
else:
	new += str(c)
print(new)