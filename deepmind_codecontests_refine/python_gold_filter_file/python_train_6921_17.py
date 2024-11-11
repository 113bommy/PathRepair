x = int(input())
*li,  = map(int, input().split())
li.sort()
cnt, ans = 0,0
for i in range(x):
	if cnt <= li[i]:
		ans += 1
		cnt += li[i]
print(ans)
