
n = int(input())
servers = list(map(int, input().split()))
Sum = sum(servers)
average = Sum//n
flag = Sum%n == 0
ans = 0
cnt = 0
for i in range(n):
	if servers[i] <= average:
		ans += average - servers[i]
		cnt += 1
left = n - cnt
if not flag:
	ans += abs(Sum%n - left)
print(ans)


