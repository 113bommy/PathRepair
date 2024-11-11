n = int(input())
k = list(map(int,input().split()))
kk = sorted(k)
count = 0
for i in range(n):
	if k[i] != kk[i]:
		count += 1;

if count == 2:
	print("YES")
else:
	print("NO")