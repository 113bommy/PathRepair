T = int(input())
for _ in range(T):
	n = int(input())
	s = input()
	while "()" in s:
		s = s.replace("()", "")
	print(len(s) / 2)