n = int(input())
lis = list(map(int,input().split()))

ans = "Yes"
m = 0
for i in range(n):
	if m - lis[i] > 1:
		ans = "No"
		break
	else:
		max = (m,lis[i])
print(ans)