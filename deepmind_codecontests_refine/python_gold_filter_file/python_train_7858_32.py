n = int(input())
l = list(map(int , input().split()))
ans = 1
cnt = 1
for i in range(1,n):
	if l[i] >= l[i-1]: 
		cnt += 1
	else:
		ans = max(cnt,ans)
		cnt = 1
cnt = max(ans,cnt)
print(cnt)