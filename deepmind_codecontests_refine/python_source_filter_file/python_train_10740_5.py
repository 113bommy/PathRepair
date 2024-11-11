q = int(input())
for _ in range(q):
	b, w = map(int, input().split())
	if w == b:
		print("YES")
		for i in range(w + b):
			print(1, i + 1)
	elif w > b:
		if w > 3 * b + 1:
			print("NO")
		else:
			print("YES")
			for i in range(2 * b + 1):
				print(2, i + 2)
			w -= b + 1
			if 0 < w <= b:
				for i in range(w):
					print(1, 2 * i + 3)
			elif w > b:
				for i in range(b):
					print(1, 2 * i + 3)
				w -= b
				for i in range(w):
					print(3, 2 * i + 3)
	else:
		if b > 3 * w + 1:
			print("NO")
		else:
			print("YES")
			for i in range(2 * w + 1):
				print(2, i + 1)
			b -= w + 1
			if 0 < b <= w:
				for i in range(b):
					print(1, 2 * i + 2)
			elif w > b:
				for i in range(w):
					print(1, 2 * i + 2)
				b -= w
				for i in range(b):
					print(3, 2 * i + 2)