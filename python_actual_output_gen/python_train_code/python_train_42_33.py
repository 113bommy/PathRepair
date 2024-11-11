n = int(input())
a = [int(i) for i in input().split()]

s = sum(a)

for k in range(max(a),100):
	if n*k-s>n*k//2:
		print(k)
		exit()
