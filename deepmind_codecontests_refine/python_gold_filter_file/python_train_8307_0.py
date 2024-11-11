from collections import Counter
import sys
MOD = 998244353
n, m = map(int, input().split())
decided = Counter()
ans = 1
d_num = 0

def kaijou(a, n):
	x = 1
	while n > 0:
		if n & 1 == 1:
			x = (x * a) % MOD
		a = (a ** 2) % MOD
		n >>= 1
	return x

for _ in range(m):
	a, b, c = map(int, input().split())
	decided[(a-1) * n + b - 1] = c
	if abs(a-b) >= 3:
		if (b-1) * n + a - 1 not in decided:
			d_num += 1
			#ans = (ans * 2) % MOD
			decided[(b-1) * n + a - 1] = c
		elif decided[(b-1) * n + a - 1] != decided[(a-1) * n + b - 1]:
			print(0)
			sys.exit()

ans = (ans * kaijou(2, ((n-2) * (n-3) // 2) - d_num)) % MOD
#print(ans)

is_empty = 0

if n*0+0 not in decided:
	is_empty += 1
if n*0+0+1 not in decided:
	is_empty += 1
if n*0+0+n not in decided:
	is_empty += 1
if n*0+0+n+1 not in decided:
	is_empty += 1

if is_empty == 0 and n*0+0 in decided:
	if (decided[n*0+0] + decided[n*0+0+n+1]) % 2 != (decided[n*0+0+1] + decided[n*0+0+n]) % 2:
		ans *= 0

if is_empty == 1 and n*0+0+n+1 not in decided and n*0+0 in decided:
	decided[n*0+0+n+1] = (decided[n*0+0+1] + decided[n*0+0+n]) % 2 - decided[n*0+0]

ans = (ans * (2 ** max(0, is_empty-1))) % MOD

#print(ans)
for i in range(n-2):

	is_empty = 0
	#if n*i+i+n+1 not in decided:
		#is_empty += 1
	if n*i+i+2 not in decided:
		is_empty += 1
	if n*i+i+2*n not in decided:
		is_empty += 1

	if is_empty == 0 and n*i+i+n+1 in decided:
		if (decided[n*i+i+2] + decided[n*i+i+n+1] + decided[n*i+i+2*n]) % 2 != 0:
			#print("hoge")
			ans *= 0

	if is_empty == 0 and n*i+i+n+1 not in decided:
		decided[n*i+i+n+1] = (decided[n*i+i+2] + decided[n*i+i+n*2]) % 2
		ans = (ans * 499122177) % MOD

	ans = (ans * (2 ** max(0, is_empty-1))) % MOD

	is_empty = 0

	if n*(i+1)+(i+1)+1 not in decided:
		is_empty += 1
	if n*(i+1)+(i+1)+n not in decided:
		is_empty += 1
	if n*(i+1)+(i+1)+n+1 not in decided:
		is_empty += 1

	if is_empty == 0 and n*(i+1)+(i+1) in decided:
		if (decided[n*(i+1)+(i+1)] + decided[n*(i+1)+(i+1)+n+1]) % 2 != (decided[n*(i+1)+(i+1)+1] + decided[n*(i+1)+(i+1)+n]) % 2:
			ans *= 0

	if is_empty == 0 and n*(i+1)+(i+1) not in decided:
		ans = (ans * 499122177) % MOD

	if is_empty == 1 and n*(i+1)+(i+1)+n+1 not in decided and n*(i+1)+(i+1) in decided:
		decided[n*(i+1)+(i+1)+n+1] = (decided[n*(i+1)+(i+1)+1] + decided[n*(i+1)+(i+1)+n]) % 2 - decided[n*(i+1)+(i+1)]

	ans = (ans * (2 ** max(0, is_empty-1))) % MOD


print(int(ans))