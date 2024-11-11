n = int(input())
dl = [0] * (2000+3)
dr = [0] * (2000+3)
for i in range(n):
	x, y = map(int, input().split())
	dl[x-y]+=1
	dr[1000-x+y]+=1
ans = 0
for i in dr:
	ans += (i*(i-1))//2
for i in dl:
	ans += (i*(i-1))//2
print(ans)