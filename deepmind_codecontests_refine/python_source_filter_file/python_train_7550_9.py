n = int(input())
s = input()
cnt = 0

if n<26:
	for i in range(0,n):
		c = s[0]
		s = s[1::]
		if c in s:
			cnt+=1
else:
	cnt = -1
print(cnt)

