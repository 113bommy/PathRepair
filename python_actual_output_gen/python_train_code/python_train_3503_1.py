n, k = map(int, input().split())
sushi = [list(map(int, input().split())) for _ in range(n)]
sushi.sort(key=lambda x: x[1], reverse=True)
#print(sushi)
num = 0
kind = set()
changable = []
for i in range(k):
	num += sushi[i][1]
	if sushi[i][0] in kind:
		changable.append(sushi[i][1])
	else:
		kind.add(sushi[i][0])

num += len(kind)**2
changable.reverse()
#print(changable)
ans = num

for i in range(k, n):
	if not changable:
		break

	if sushi[i][0] not in kind:
		num += sushi[i][1] + 2*len(kind)+1 - changable.pop()
		#print(num, kind)
		kind.add(sushi[i][0])
		ans = max(ans, num)


print(ans)