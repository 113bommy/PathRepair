n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

count =  n
pointer = 0
# for i in range(n):
# 	if pointer > m:
# 		break
# 	for j in range(pointer, m):
# 		if a[i] <= b[j] :
# 			count -= 1
# 			pointer = j + 1
# 			break
# 	if count == 0:
# 		print("0")
# 		exit()
i = 0
j = 0

while (i < n & j < m):
	if b[j] >= a[i]:
		i += 1
		j += 1
	else:
		j += 1
print(n - i)
	
# print(count)