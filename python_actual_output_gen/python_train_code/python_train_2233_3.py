n = int(input())
xs = [int(x) for x in input().split()]

arr_k = [xs[0]]

for i in range(1, len(xs)):
	arr_k.append(xs[i] - xs[i - 1])

soln = []
print(arr_k)
for k in range(1, len(arr_k) + 1):
	mul = len(arr_k) // k + 1
	# print(k,arr_k[:k], mul)
	tmp = (arr_k[:k] * mul)[:len(arr_k)]
	# print(k, tmp)
	if tmp == arr_k:
		soln.append(k)
print(len(soln))
print(" ".join(map(str, soln)))