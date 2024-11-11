T = int(input())
for i in range(T):
	n = int(input())
	l = list(map(int,input().split()))
	if 2048 in l:
		print("YES")
	else:
		t = 0
		if 1 in l:
			k = l.count(1)
		else:
			k = 0
		for i in range(1,10):
			if 2**i in l:
				k = l.count(2**i) + k//2
			elif t >=0:
				k = k//2
			if k <= 1:
				t = 0
			t = t + k
		if t >= 2:
			print("YES")
		else:
			print("NO")
