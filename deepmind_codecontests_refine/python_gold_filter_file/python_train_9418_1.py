b = str(input())
maxval = str(-1)
lol = int(b[-1])

for i in range(len(b)):
	if (b[i] == "0" or b[i] == "2" or b[i] == "4" or b[i] == "6" or b[i] == "8") and (int(b[i]) < lol):
		c = b[:i] + b[len(b)-1] + b[i+1:len(b)-1] + b[i]
		maxval = max(maxval, c)
		break

for i in range(len(b)-1,-1,-1):
	if (b[i] == "0" or b[i] == "2" or b[i] == "4" or b[i] == "6" or b[i] == "8") and (int(b[i]) > lol):
		d = b[:i] + b[len(b)-1] + b[i+1:len(b)-1] + b[i]
		maxval = max(maxval, d)
		break

print(maxval)