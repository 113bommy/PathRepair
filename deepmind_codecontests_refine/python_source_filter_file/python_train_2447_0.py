
n = int(input())
l = list(map(int, input().split()))

if 1 not in l:
	print(0)
	exit()

ind = l.index(1)
ind2 = l[::-1].index(1)
co = 0
ans = 0
for i in range(ind, n - ind2):
	if l[i] == 1:
		ans += 1
		if co < 2:
			ans += co
			co = 0
		
	else:
		co += 1

print(ans)
