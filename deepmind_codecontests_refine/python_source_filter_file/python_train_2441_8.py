def print_tube(a):
	print(len(a),end = " ")
	print(" ".join(map(lambda x: " ".join(str(i) for i in x), a)))
n, m, k = map(int, input().split())
res = [(x,y) for x in range(n) for y in range(m)[::(1 if (x%2 == 0) else -1)]]
for i in range(k-1):
	print_tube(res[2*i:2*i+2])
print_tube(res[2*k-2:])