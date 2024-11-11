n = int(input())
s = [[i for i in input().split()] for i in range(n)]
ans = s[0][0]
cnt = 0

for i in range(n):
	a = sum(int(j) for j in s[i][4::])+int(s[i][1])*100-int(s[i][2])*50
	if a>cnt:
		cnt = a
		ans = s[i][0]
print(ans)