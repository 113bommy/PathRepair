s = input()
n = int(input())
if n > len(s):
	print('impossible')
else:
	print(max(0,n-len(set(s))))
