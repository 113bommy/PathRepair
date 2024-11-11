n = int(input())
a = list(map(int, input().split()))
a += a

ans = 0
cnt = 0
for i in a:
	if i == 1:
		cnt += 1
	else:
		ans = max(ans, cnt)
		cnt = 0
ans = max(ans, cnt)
print(ans)