n = input()
s = input()
s = s.split()
s = [int(i) for i in s]
s.sort()
if s[0] == 1:
	print(-1)
else:
	print(s[0]-1)