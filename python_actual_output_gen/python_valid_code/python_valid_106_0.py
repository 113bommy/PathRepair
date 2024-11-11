n = int(input())
lst = list(map(int,input().split()))
ans = "NO"
for i in range(n):
	if (lst[lst[lst[i]-1]-1] == i-1):
		ans = "YES"
print(ans)