n = int(input())
s = input()
cnt = 0
if n == 1:
	if s == '1':
		print("YES")
	else:
		print("NO")
	exit()

if s[0] == '0':
	cnt+=1

for i in range(1, n):
	if (s[i] == s[i-1] and s[i] == '1'):
		print("NO")
		exit()
	if s[i] == '0':
		cnt += 1
	if cnt == 3:
		print("NO")
		exit()
	if s[i] == '1':
		cnt = 0
if (s[0] == '0' and s[1] == '0') or (s[-1] == 0 and s[-2] == 0):
	print ("NO")
else:
	print ("YES")