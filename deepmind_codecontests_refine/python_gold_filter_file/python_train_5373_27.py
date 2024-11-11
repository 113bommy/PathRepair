I = lambda:int(input())
ID = lambda:map(int, input().split())
IL = lambda:list(ID())
s = list(input())
k = I()
a = list(set(s))
if k == len(a) and s == a:
	print(0)
elif len(s)>=k:
	print(max(0, k-len(a)))
else:
	print('impossible')
