n = int(input())
s = input()

count = 0
for i in range(len(s)):
	if i != len(s)-1 and s[i] == s[i+1]:
		count += 1
	else:
		continue
print(count)