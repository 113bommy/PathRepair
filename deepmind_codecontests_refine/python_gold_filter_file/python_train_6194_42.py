'''input
5
1 2 3 4 5
'''
n = int(input())
l = list(map(int, input().split()))
if 1 in l:
	print(-1)
else:
	print(1)