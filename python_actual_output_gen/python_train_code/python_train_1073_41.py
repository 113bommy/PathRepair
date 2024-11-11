len = int(input())
s = input()
ans = s[0]

for i in range(1, len):
	if s[i] in 'aeiou' and s[i-1] in 'aeiou':
		continue
	else:
	 ans+=s[i]

print (ans)