for _ in range(int(input())):
	s = int(input())
	if(s >= 10):
		s -= 10
		res = s // 9 + s + 1 + 10
	else :
		res = 0
	print(res)