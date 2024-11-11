n = int(input())
for i in range(n):
	s = int(input())+int(input())
	if len(str(s))>80:
		print("overflow")
	else:
		print(s)