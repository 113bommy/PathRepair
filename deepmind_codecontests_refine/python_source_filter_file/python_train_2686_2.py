p = int(input())
a = list(map(int, input().split()))

list_size = p-1

f_list = [1] * list_size
f_r_list = [1] * list_size

for i in range(list_size - 1):
	f_list[i + 1] = int((f_list[i] * (i + 2)) % p)

f_r_list[-1] = pow(f_list[-1], p - 2, p)

for i in range(2, list_size + 1):
	f_r_list[-i] = int((f_r_list[-i + 1] * (list_size + 2 - i)) % p)

def comb(n, r):
	if n < r:
		return 0
	elif n == 0 or r == 0 or n == r:
		return 1
	else:
		return (((f_list[n - 1] * f_r_list[n - r - 1]) % p) * f_r_list[r - 1]) % p 

pows = [[1] for x in range(p)]
for i in range(p):
	for _ in range(p-1):
		pows[i].append((pows[i][-1] * i) % p)

ans = [0 for _ in range(p)]
for i, x in enumerate(a):
	if x == 0:
		continue
	ans[0] += 1
	ans[0] %= p
	for j in range(p):
		ans[j] -= pows[p-i][p-1-j] * comb(p-1, j)
		ans[j] %= p

print(*ans)