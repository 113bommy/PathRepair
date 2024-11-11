N=int(input())

ans = "No"

for i in range(4, N+1, 4):
	if max(0, N-i)%7 == 0:
		ans = "Yes"

print(ans)
