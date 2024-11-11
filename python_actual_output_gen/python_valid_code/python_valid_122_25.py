
for _ in range (int(input())):
	n = int(input())
	s = input()
	if n == 2 and s[0]==s[1]:
		print('NO')
	else:
		print("YES")
		print(2)
		print(s[0],s[1:])