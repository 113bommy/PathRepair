s = input()
n = int(input())
if n > len(s):
	print('impossible')
else:
	print(abs(n-len(set(s))))
