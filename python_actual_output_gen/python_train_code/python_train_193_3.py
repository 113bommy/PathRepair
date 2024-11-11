n,L,a = map(int,input().split())
list1 = []
for i in range(n):
	t = list(map(int,input().split()))
	list1.append(t)
ans = 0
for i in range(n):
	k = list1[i][0] + list1[i][1]
	if i == n-1:
		k = L - k
	else:
		k = list1[i+1][0] - k
	ans = ans + k//a
if n == 0:
	ans = L//a
else:
	ans = ans + list1[i][0]//a
print(ans)