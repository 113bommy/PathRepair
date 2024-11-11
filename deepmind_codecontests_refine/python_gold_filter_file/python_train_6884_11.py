s = list(input())

start, end = -1, -1
for i in range(len(s)):
	if(s[i] == '['):
		start = i
		break
for i in range(len(s) - 1, -1, -1):
	if(s[i] == ']'):
		end = i
		break

count = 2
ma = 0
for i in range(start + 1, end):
	if(s[i] == ':' and count == 2):
		count += 1
	elif(s[i] == '|' and count > 2):
		count += 1
	elif(s[i] == ':' and count > 2):
		count += 1
		if(count > ma):
			ma = count
		count -= 1

if(ma < 4 or start == -1 or end == -1):
	print(-1)
else:
	print(ma)